#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //check command line args
    while (argc != 2)
    {
        //fprintf to stderr if incorrect input
        fprintf(stderr, "please enter ./recover [filename]");
        return 1;
    }

    // assign input file (deleted card) name
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");

    //check if input file was opened (if inptr points to infile or NULL)
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //define image buffer (array of BYTE) for holding 512 byte blocks
    typedef uint8_t BYTE;
    BYTE buff[512];
    int buffer_size = sizeof(buff);

    //initialize image name counter
    int image_number = 0;

    //initialize filename
    char iterative_filename[8];

    FILE *image_write = NULL;

    do //reads from infile to buff, checks buff for jpeg header
    {
        fread(buff, buffer_size, 1, inptr);

    }
    while (buff[0] != 0xff && buff[1] != 0xd8 &&
           buff[2] != 0xff && (buff[3] & 0xf0) != 0xe0);

    while (image_number == 0) //writes first block to first jpeg
    {
        //open new outfile with name 000.jpeg - xxx.jpeg
        sprintf(iterative_filename, "%03d.jpg", image_number);
        image_write = fopen(iterative_filename, "w");
        fwrite(buff, buffer_size, 1, image_write);//TODO check fwrite
        image_number ++;
    }

    //loop after start of jpegs has been found, repeats while there buffer_size left in infile
    while (fread(buff, buffer_size, 1, inptr) == 1)
    {
        //if the current block is the start of a jpeg
        if (buff[0] == 0xff && buff[1] == 0xd8 &&
            buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0)
        {
            //close the previous file, iterate filename, open file with new filename
            //write buff to new file, iterate image number for new filename
            fclose(image_write);
            sprintf(iterative_filename, "%03d.jpg", image_number);
            image_write = fopen(iterative_filename, "w");
            fwrite(buff, buffer_size, 1, image_write);
            image_number ++;
        }

        else //while infile is still within a jpeg, write to outfile
        {
            fwrite(buff, buffer_size, 1, image_write);
        }
    }

    fclose(image_write); //close current jpeg
    fclose(inptr); //close infile
}