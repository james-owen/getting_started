#include <stdio.h>
#include <cs50.h>

int main(void)
{

    //initialize height variable: h

    int h;

    //get input, set height to inputted value

    do
    {
        printf("Height?");
        h = get_int();
    }

    while (h < 0 || h > 23);

//set int i to 0, run the below then add 1 to i--makes the below run through i = 0,1,2,etc. up to height

    for (int i = 0; i < h; i++)
    {

        // also works: for (int space = h - 1 - i; space > 0 && space < h; space--), but the below is cleaner

        //prints 1 less than h-i spaces per row
        for (int space = i + 1; space < h; space++)
        {
            printf(" ");
        }

        //print hashes for left: row # + 1

        for (int left = h - i; left <= h; left++)
        {
            printf("#");
        }

        //print gap (2 spaces)

        printf("  ");

        //print hashes for right side (same as left)

        for (int right = h - i; right <= h; right++)
        {
            printf("#");
        }

        //print new line \n

        printf("\n");


    }

}