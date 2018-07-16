#include <stdio.h>
#include <stdlib.h>
#include "whitespaces.h"

/*
 * Returns the category of the image using the "magic" number
 */
int findCategory (void) {
    int category = 0;
	int c = getchar();
    /* First character is P */
	if (c!='P') {
		fprintf(stderr, "Input error!\n");
		exit(-1); 
	}
	putchar(c);
	c = getchar();
    /* The second character is a number between 1 and 6, that indicates the category */
	if (c >= '1' && c <= '6') { 
		category = c-'0';
		putchar(c-1);
	}
	else { 
		fprintf(stderr, "Input error!\n");
		exit(-2);
	}
    return category;
}

/*
 *
 */
int readHeader (int *width, int *height, int *max, int category) {
    int c;
    putchar('\n');
	c = eatWhiteSpaces(); /* after the magic number, there is "white" space */
	c = eatComments(c); /* checking if there are comments */
    /* After the "white" space, the width of the image is following */
	*width = 0; 
	while (!isWhitespace(c)) {
		putchar(c); 
		*width = 10 * (*width) + (c-'0');
		c = getchar();
	}
	putchar(' ');
	c = eatWhiteSpaces(); /* after the width, there is a white space */
    /* After the "white" space, the height of the image is following */
	*height = 0;
	while (!isWhitespace(c)) {
		putchar(c);
		*height = 10 * (*height) + (c-'0');
		c = getchar();
	}
	putchar('\n');
	c = eatWhiteSpaces(); /* after the height, there is a white space */
    /* if image is b&w, it has a maximum pixel value (usually 255) */
	if (category != 1 && category != 4) {
		*max = 0;
		while (!isWhitespace(c)) {
            /* Want to write to the output image only if input image is an rgb image */
			if (category % 3 == 0) putchar(c);
			*max = 10 * (*max) + (c-'0');
			c = getchar();
		}
		if (category % 3 == 0) putchar('\n');
		c = eatWhiteSpaces();
	} 
    return c;
}