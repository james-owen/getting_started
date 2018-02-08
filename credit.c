#include <cs50.h>
#include <math.h>
#include <stdio.h>

//initialize array card_array


int main(void)
{
    unsigned long long card_num;

    printf("Please enter a card number: ");

    // gets card number input, assigns to the variable card_num
    card_num = get_long_long();

    //count number of digits (divide by 10 and increase counter each time)
    unsigned long long card_count = card_num;

    //initialize counter variable, ie. length of card number, for global use (within main and checksum)
    int count = 0;

    while (card_count != 0)
    {
        card_count /= 10;
        count++;
    }

    int card_array[count];

    unsigned long long card_last = card_num;

    //puts the digits of card_num into an card_array, last to first
    for (int i = 0; card_last != 0; i++)
    {
        //eprintf("card_last is currently %llu\n", card_last);

        int last = card_last % 10;

        //eprintf("Last digit is %d\n", last);

        card_array[i] = last;

        card_last = card_last / 10;
    }

    //printf("\nElements in array are: ");

    for (int j = 0; j < count; j++)
    {
        //printf("Element [%d] is %d  \n", j, card_array[j]);
    }

    int sum_one = 0;
    int sum_two = 0;
    int sum_array[count];

    for (int s = 0; s < count; s++)
    {
        sum_array[s] = 0;
    }
    //adds every other digit of card_num and multiplies by 2. I tried more elegant solutions, but this is elegant because it works.

    for (int k = 1; k < count; k += 2)
    {
        sum_one = card_array[k] * 2;

        //eprintf("sum one is currently %d\n", sum_one);

        int sum_count = k - 1;

        if (sum_one < 10)
        {
            sum_array[sum_count] = sum_one;
        }

        else
        {
            sum_array[sum_count] = sum_one % 10;
            sum_array[k] = (sum_one / 10);
        }

    }

    for (int p = 0; p < count; p++)
    {
        //printf("Sum array element [%d] is %d  \n", p, sum_array[p]);
    }

    unsigned long long digit_product = 0;

    for (int o = 0; o < count; o++)
    {
        digit_product += sum_array[o];
        //eprintf("Digit product is %llu\n", digit_product);
    }

    for (int l = 0; l < count; l += 2)
    {
        sum_two += card_array[l];
        //eprintf("sum two is: %i\n" , sum_two);
    }

    int sum_three = digit_product + sum_two;

    //eprintf("final sum is: %i\n", sum_three);

    int check = sum_three % 10;

    //eprintf("Final check is %d\n", check);

    if (check == 0 && count == 15 && card_array[14] == 3 && (card_array[13] == 4
            || card_array[13] == 7))
    {
        printf ("AMEX\n");
    }

    else if (check == 0 && count == 16 && card_array[15] == 5 && card_array[14] > 0
             && card_array[14] < 6)
    {
        printf ("MASTERCARD\n");
    }

    else if ((check == 0) && ((count == 13 && card_array[12] == 4) || (count == 16
                              && card_array[15] == 4)))
    {
        printf ("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}

