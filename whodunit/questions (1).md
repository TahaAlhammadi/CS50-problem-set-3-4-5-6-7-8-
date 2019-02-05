# Questions

## What's `stdint.h`?
__stdint.h is a header file in the C standard library introduced to 
allow programmers to write more portable code by providing a set of typedefs that 
specify exact-width integer types__


## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?
__They are a defined data types which empower us with more manipulations with bytes and bits
uint8_t is a type of unsigned integer of length 8 bits and is the same as a byte. its shorthand for.
unint32_t is a numeric type that guarantees 32 bits, the value is unsigned, meaning that the range of values goes from 0 to 232 - 1
Because they are ,except int32_4, unsigned, their first bit (Most Significant Bit (MSB)) is not reserved for signing.


## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?
__Byte: 1
  DWORD: 4
  LONG: 4
  WORD: 2 __

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."
__The first two bytes specify the file is a bitmap with the words "BM", or the hex 0x4D42 .__
TODO

## What's the difference between `bfSize` and `biSize`?
__ bfSize stand for bytes file Size
   biSize stands for bytes BITMAPINFOHEADER Size __
TODO

## What does it mean if `biHeight` is negative?
__ If biHeight is positive, the bitmap is a bottom-up DIB and its origin is the lower-left corner. 
If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.___

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?
__ biBitCount __

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?
__ fopen will return null if it cannot open the file. This can happen 
if there is not enough memory or the file cannot be found.__

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)
__ Because it specifies how many elements you want to read, and 
we're always reading a struct so we only need 1 struct.__

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?
3
TODO

## What does `fseek` do?
__It moves to a specific location in a file.__

## What is `SEEK_CUR`?

TODO
