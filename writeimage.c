#include <stdio.h>
#include "whitespaces.h"
#include "convertion.h"

/*
 *  Take an ascii grayscale and convert it to an ascii b&w image
 */
void convertP2toP1 (int c, int height, int width, int max) {
	for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            int b=0;
            /* 
             * Reading characters until the first "white" space. 
             * Then, I convert the characters to an integer.
             */
            while (!isWhitespace(c)) {
                b = 10*b+(c-'0');
                c = getchar();
            }
            /* I convert the pixel to 0 or 1 and write it to the output image */
            putchar(grayscaleToBW(b,max)+'0');
            putchar(' ');
            c = eatWhiteSpaces();
        }
        putchar('\n'); /* change line to the output file */
	}
}

/*
 *  Take an ascii rgb and convert it to an ascii grayscale image
 */
void convertP3toP2 (int c, int width) {
    int count = 0;
    while (c != EOF) {
        /* The first characters indicate the red compnent */
        int red = 0;
        while (!isWhitespace(c)) {
            red = 10*red + (c-'0');
            c = getchar();
        }
        c = eatWhiteSpaces();
        /* The first characters indicate the green compnent */
        int green = 0;
        while (!isWhitespace(c)) {
            green = 10*green + (c-'0');
            c = getchar();
        }
        c = eatWhiteSpaces();
        /* The first characters indicate the blue compnent */
        int blue = 0;
        while (!isWhitespace(c)) {
            blue = 10*blue + (c-'0');
            c = getchar();
        }
        c = eatWhiteSpaces();
        /* Take the three components, produce the grayscale pixel and write the pixel to the output image */
        int b = rgbToGrayscale(red, green, blue);
        writeAsciiOfPositiveInteger(b);
        count++;
        if (count % width == 0) putchar('\n');
        else putchar(' ');
    }
}

/*
 *  Take a binary grayscale and convert it to a binary b&w image
 */
void convertP5toP4 (int c, int width, int max) {
    int b = 0;
    int bit_counter = 0;
    int byte_counter = 0;
    while (c != EOF) {
        /* Every 8 bits, write 1 character (= 1 byte) to the output */
        if (bit_counter == 8) {
            putchar(b);
            bit_counter = 0;
            b = 0;
        }
        /* Logical or in order to write the result of the convertion to the last bit of the current byte */
        b = b << 1;
        b = b | grayscaleToBW(c, max);
        bit_counter++;
        /* If I reach the end of the line */
        if ( (byte_counter != 0) && ((byte_counter + 1) % width == 0) ){
            /* Fill with 1 the remaining bits of the last byte */
            while (bit_counter != 8) {
                b = b << 1;
                b = b | 1;
                bit_counter++;
            }
            putchar(b);
            bit_counter = 0;
            b = 0;
        }
        c = getchar();
        byte_counter++;
    }
}


/*
 *  Take a binary rgb and convert it to a binary grayscale image
 */
void convertP6toP5 (int c) {
    while (c != EOF) {
        int red = c;
        int green = getchar();
        int blue = getchar();
        putchar(rgbToGrayscale(red,green, blue));
        c = getchar();
    }
}