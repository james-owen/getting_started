#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    float cchange;
    int rcents;

    do
    {
        printf("Change?");
        change = get_float();
    }

    while (change <= 0);

    //printf("input as a float is %.2f \n", change);

    //convert to int: multiply by 100 and round to an even cent

    //float to another float (original * 100)

    cchange = change * 100;

    //printf("times 100 is %.2f\n", cchange);

    rcents = round(cchange);

    //divide with quarters

    int quarter = 25;
    int count = 0;

    while (rcents >= quarter)
    {
        count ++;
        rcents = rcents - quarter;
    }

    int dime = 10;

    while (rcents >= dime)
    {
        count ++;
        rcents = rcents - dime;
    }

    int nickel = 5;

    while (rcents >= nickel)
    {
        count++;
        rcents = rcents - nickel;
    }

    int penny = 1;

    while (rcents >= penny)
    {
        count++;
        rcents = rcents - penny;

    }

    //output final total count

    printf("%i\n", count);

}
