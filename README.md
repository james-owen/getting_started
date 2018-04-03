# Questions

## What's `stdint.h`?

Allows definitions of types to the byte, which allows for use on different systems. Since bmp is standardized, variations in the sizes of the types would create problems.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are types that allocate a certain amount of memory--the number of bits specified. These are 'u' unsigned or '' signed 'int' integers of the size 'n' the number of bits '_t' type.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE: 1 DWORD: 4, LONG: 4, WORD: 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

bfType: BM, see: https://msdn.microsoft.com/en-us/library/dd183374(v=vs.85).aspx

## What's the difference between `bfSize` and `biSize`?

bfSize is in BITMAPFILEHEADER and holds the size of the file, while bisize is in BITMAPINFOHEADER and holds the size of that struct.

## What does it mean if `biHeight` is negative?

This indicates a 'top down DIB' and sets the origin to the upper left.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

fopen returns NULL if the file does not exist.

## Why is the third argument to `fread` always `1` in our code?

fread should read the file once.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3 (I found this by running the code with the value of 3 to be sure. This is analogous to small.bmp.)

## What does `fseek` do?

fseek changes the location of the file pointer when reading from a file via an 'offset.'

## What is `SEEK_CUR`?

SEEK_CUR is the current position of the file pointer.
