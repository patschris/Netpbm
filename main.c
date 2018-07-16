#include <stdio.h>
#include "whitespaces.h"
#include "convertion.h"
#include "readimage.h"
#include "writeimage.h"

int main (void) {
	int c, max, width, height, category;
	category = findCategory();
	c = readHeader (&width, &height, &max, category);
	/* Make the proper convertion */
	switch (category) {
		case 1:	printf("Cannot convert a BW image of ASCII encoding!\n");
				break;
		case 2: convertP2toP1 (c, height, width, max);
				break;
		case 3: convertP3toP2 (c, width);
				break;
		case 4: printf("Cannot convert a BW image of binary encoding!\n");
				break;
		case 5: convertP5toP4 (c, width, max);
				break;
		case 6: convertP6toP5 (c);
				break;
		default:printf("Never should be here!\n");
				break;
	}
	return 0;
}