#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[argc])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");

        return 1;
    }
    //convert string input number to int
    int input = atoi(argv[1]);
    int key;

    //take input, divide by 26 (%26), remainder is (key)

    if (input < 27)
    {
        key = input;
    }

    else
    {
        key = input % 26;
    }

    //eprintf ("Key is: %i\n", key);

    printf ("Plaintext: ");

    string plaintext = get_string();

    //eprintf("Plaintext is %s \n", plaintext);

    int length = strlen(plaintext);

    //eprintf("Length of strings is %i \n", length);

    string ciphertext = plaintext;

    //loop runs through length of input
    for (int k = 0; k < length; k++)
    {
        if (plaintext[k] < 65)//if input is <65 it's punctuation
        {
            ciphertext[k] = plaintext[k];
        }

        else if (plaintext[k] > 64 && plaintext[k] < 91)// if input is in this range, it's uppercase
        {
            if (plaintext [k] + key < 91)//check to see if it's within the alphabet (up to 90 / Z)
            {
                ciphertext[k] = (plaintext[k] + key);
            }

            else
            {
                ciphertext[k] = (plaintext[k] + key - 26);//'loops' around, ie subtracts 26 if it goes over
            }
        }

        else if (plaintext[k] > 96 && plaintext[k] < 123)//lowercase
        {
            if (plaintext [k] + key < 123)//check to see if z / 122 or below
            {
                ciphertext[k] = (plaintext[k] + key);
            }

            else
            {
                ciphertext[k] = (plaintext[k] + key - 26);//loops back if above 122
            }
        }

    }

    //a check to see what each element of ciphertext is in ascii
    //for (int l = 0; l < length; l++)
    //{
        //printf("Value of each letter: %i\n", ciphertext[l]);
    //}

    //print all the values of string ciphertext
    printf("ciphertext: %s\n", ciphertext);

}