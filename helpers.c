// Helper functions for music

#include <cs50.h>
#include <math.h>
//#include <stdio.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //pulls out digits of fraction
    int i = atoi(&fraction[0]);
    int j = atoi(&fraction[2]);

    //eprintf("First number: %i\nSecond number: %i\n", i, j);

    float num = i;
    float den = j;

    //makes a new fraction (with note duration)
    float k = (num / den);

    //eprintf("As a decimal: %.5f", k);

    int eighths = 0;
    float one_rest = 1.0 / 8.0;

    //eprintf("Value of one_rest: %.5f\n", one_rest);

    //divides k into 1/8 sized pieces
    do
    {
        k = k - one_rest;

        //eprintf("Current k value: %.5f\n", k);

        eighths++;

    }
    while (k >= one_rest);

    //returns the duration divided by an 8th note (1/8 fraction)
    return eighths;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //setting values for number of semitones away from A within a given octave--
    //B is up 2, C is down 9, etc.
    int C = -9, D = -7, E = -5, F = -4, G = -2, A = 0, B = 2;

    //initialize int note_name to the value of int C
    int note_name = C;

    //set char note_name to its int equivalent (above). Accounts for input which isupper and islower.
    if (note[0] == 'C' || note[0] == 'c')
    {
        note_name = C;
    }

    else if (note[0] == 'D' || note[0] == 'd')
    {
        note_name = D;
    }

    else if (note[0] == 'E' || note[0] == 'e')
    {
        note_name = E;
    }

    else if (note[0] == 'F' || note[0] == 'f')
    {
        note_name = F;
    }

    else if (note[0] == 'G' || note[0] == 'g')
    {
        note_name = G;
    }

    else if (note[0] == 'A' || note[0] == 'a')
    {
        note_name = A;
    }

    else if (note[0] == 'B' || note[0] == 'b')
    {
        note_name = B;
    }

    //accidental offset--changed if # or b is present in note string
    int accidental = 0;

    int default_octave = 4;

    //freqency of 'home note' A4 is stored as 440
    int frequency_A4 = 440;

    //semitones per octave is 12
    float o_semitones = 12;

    //declare octave_number variable
    int octave_number = 0;

    int name_length = strlen(note);

    //assign to inputted octave number
    if (name_length == 3)
    {
        octave_number = atoi(&note[2]);

        //eprintf("Octave number: %i Accidental: %c\n", octave_number, note[1]);

        if (note[1] == '#')
        {
            accidental = 1;
        }

        else if (note[1] == 'b')
        {
            accidental = -1;
        }
        //eprintf("Accidental: %i\n", accidental);
    }

    if (name_length == 2)
    {
        octave_number = atoi(&note[1]);
    }

    //eprintf("Octave Number: %i\n", octave_number);

    //creates 'octave multiplier'
    //based on how far it is from the 4th (default) octave.
    //This is then multipled by the number of semitones per octave (o_semitones)
    //(ex. octave 3 would require subtracting 12 ((4-3) * 12) == -12 )
    int octave_multiplier = ((octave_number) - default_octave) * o_semitones;

    //finally, we can calculate the distance to A4 for any note with the following
    float distance_a4 = octave_multiplier + note_name + accidental;

    //calculates the 'power' for our standard formula: 2^note_power or 2^(n/12) where n is distance from A4
    float note_power = (distance_a4 / o_semitones);

    //calculates frequency using the standard formula
    //rounds the answer
    int frequency = round((pow(2, note_power)) * frequency_A4);

    return frequency;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    string rest_string = "";

    if (strcmp(rest_string, s) == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

