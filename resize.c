// Resizes a bitmap (.bmp) file by an int factor

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize [multiplier] [infile] [outfile]\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER, send to bf
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER, send to bi
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    int old_height = abs(bi.biHeight);

    int old_width = bi.biWidth;

    int old_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //Scale biWidth (*= n)
    bi.biWidth *= n;

    //Scale biHeight (*= n)
    bi.biHeight *= n;

    // determine padding for scanlines
    int new_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //Scale biSizeImage
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + new_padding) * abs(bi.biHeight);

    //Scale bfSize
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines (old_height)
    for (int h = 0; h < old_height; h++)
    {
        for (int m = 0; m < n - 1; m++) //n-1 times
        {
            for (int p = 0; p < old_width; p++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile, send to triple
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int r = 0; r < n; r++)
                {
                    // write triple to outfile, n times
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            int scanline_size = old_width * sizeof(RGBTRIPLE);

            fseek(inptr, -scanline_size, SEEK_CUR);

            //write new padding
            for (int q = 0; q < new_padding; q++)
            {
                fputc(0x00, outptr);
            }

        }

        //last scanline or for n = 1
        for (int p = 0; p < old_width; p++)
        {

            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile, send to triple
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int s = 0; s < n; s++)
            {
                // write triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }

        //write new padding
        for (int l = 0; l < new_padding; l++)
        {
            fputc(0x00, outptr);
        }

        // skip over old padding in infile, if any
        fseek(inptr, old_padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
