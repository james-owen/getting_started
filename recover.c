#include <stdio.h>
#include <stdint.h>

int main(argc, argv)
{

    //check command line args
    while (argc != 2)
    {
        //fprintf to stderr
        fprintf(stderr, "please enter ./recover [filename]");
        return 1;
    }

    // assign input file (deleted card) name
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //initialize image name counter
    int image_number = 0;

    //define image buffer for searching 512byte blocks
    typedef uint8_t BYTE;
    BYTE buffer = [512];
    buffer_size = sizeof(buffer);

    //while there's still image to search, keep searching
    while(inptr / !EOF)
    {

    //open new outfile with name 000.jpeg - xxx.jpeg

        iterative_name = fprintf("%03d.jpeg",image_number);

        fopen(iterative_name, "w");

        fwrite(inptr, buffer_size, 512, iterative_name);

        while(writing to outfile, until end of jpeg write)
        //iterate over blocks / read a 'check block' to determine whether it's a jpeg

        fread(inptr, 512, , );

        //test for jpeg--should return true
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)


        // if no, keep going
        while (current block does not start with 0xff 0xd8 0xff)
        {
            keep going
        }

        // if block starts jpeg, start writing to outfile

        fwrite(outfile, sizeof(BYTE), 512, );


        //keep checking infile, one 'check block' at a time

        //when finding jpeg start, end writing to outfile, and start a new outfile

}



}