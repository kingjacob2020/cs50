#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    //ensure porper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./ recover image");
        return 1;
    }

    //remember file names
    char *infile = argv[1];

    //open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // create buffer space
    unsigned char buffer[512];

    //create file name space
    char filename[8];

    //file name depends on image number
    //init counter to keep track of image number
    int img_num = 0;

    //create output file
    FILE *outptr;

    //create a flag to know if jpeg open or not
    bool jpeg = false;

    //read memory card
    //jpeg are stored side by side
    //go through every block of buffer size (512)
    while (fread(buffer, sizeof(buffer), 1, inptr))
    {
        //find beginning of jpeg
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //if we already have an open jpeg || jpeg == true
            if (jpeg)
            {
                //close opened file first
                fclose(outptr);
                //set flag to false
                jpeg = false;
            }
            //create new file name for it
            sprintf(filename, "%03i.jpg", img_num);
            //open output file in write mode
            //we need an empty file for wrting
            outptr = fopen(filename, "w");
            //write current buffer to file
            fwrite(buffer, sizeof(buffer), 1, outptr);
            //set flag to true
            jpeg = true;
            //increment filename counter
            img_num++;
        }
        //if it doesnt start with a jpeg header
        else
        {
            //but jpeg is still holding a jpeg || jpeg == true
            if (jpeg)
            {
                //write left buffer to file
                fwrite(buffer, sizeof(buffer), 1, outptr);
            }
        }
    }

    //close infile
    fclose(inptr);

    //close outfile
    fclose(outptr);

    //success
    return 0;
}
