#include <stdio.h>
#include <cs50.h>

int main(void)
{

    //initialize height variable, height

    int height;

    //get input, set height to inputted value

    do
    {
        printf("Height?");
        height = get_int();

    }
    while (height < 0 || height > 23);

//set int i to 0, run the below then add 1 to i--makes the below run through 0,1,2,etc.
    for (int i = 0; i < height; i++)
    {
        // print spaces--there should be height - 1 - i spaces in each row
        for (int space = 0; space < height - 1 - i; space++)
        {
            printf(" ");
        }
        //print hashes--there should be row number + 2 hashes in each row
        for (int j = 0; j < i + 2; j++)
        {
            printf("#");
        }
        // print a new line
        printf("\n");
    }

}


