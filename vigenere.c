#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[argc])
{

    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");

        return 1;
    }


    int key_length = strlen(argv[1]);

    char keyword[key_length];
    int key[key_length];

    for (int k = 0; k < key_length; k++)
    {
        keyword[k] = argv[1][k];

        if ((isalpha(keyword[k])) == 0)
        {
            printf("Please input letters\n");

            return 1;
        }

    }

    for (int l = 0; l < key_length; l ++)
    {
        if (keyword[l] >= 'A' && keyword[l] <= 'Z')
        {
            key[l] = keyword[l] - 'A';
        }

        else if (keyword[l] >= 'a' && keyword[l] <= 'z')
        {
            key[l] = keyword[l] - 'a';
        }
    }

    //printf("key is: ");
    //for (int m = 0; m < key_length; m ++)
    //{
    //    printf("%i, ", key[m]);

    //}

    //printf("\n");

    string plaintext = get_string("Plaintext:");

    int text_length = strlen(plaintext);

    //printf("Letters of plaintext:");
    //for (int o = 0; o < text_length; o++)
    //{
    //printf("%c\n", plaintext[o]);
    //}
    //counter to go through the key, but only if there's a char (not a space)
    int counter = 0;

    for (int n = 0; n < text_length; n++)
    {

        int key_cycle = (counter % key_length);

        if (plaintext[n] > 64 && plaintext[n] < 91)// if input is in this range, it's uppercase
        {
            if (plaintext[n] + key[key_cycle] < 91)//check to see if it's within the alphabet (up to 90 / Z)
            {
                plaintext[n] = (plaintext[n] + key[key_cycle]);
                counter++;
            }

            else
            {
                plaintext[n] = (plaintext[n] + key[key_cycle] -
                                26);//'loops' around, ie subtracts 26 if it goes over
                counter++;

            }

        }

        else if (plaintext[n] > 96 && plaintext[n] < 123)//lowercase
        {
            if (plaintext[n] + key[key_cycle] < 123)//check to see if z / 122 or below
            {
                plaintext[n] = (plaintext[n] + key[key_cycle]);

                counter++;
            }

            else
            {
                plaintext[n] = (plaintext[n] + key[key_cycle] - 26);//loops back if above 122

                counter++;
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);

}