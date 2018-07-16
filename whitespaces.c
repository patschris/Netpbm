#include <stdio.h>

/*
 * Checks if a character is "white space"
 */
int isWhitespace (char c) {
	if (c == '\n' || c == '\t' || c == ' ') return 1;
	else return 0;
}

/*
 * Consumes the "white spaces" and returns the next character after them
 */
int eatWhiteSpaces(void) {
	int c;
	do {
	  	c = getchar();
	} while (isWhitespace(c));
	return c; 
}

/*
 * Consumes the "comments" and returns the next character after them
 * Maybe, there are multiple successive lines with comments
 */
int eatComments(int c) {
	while (c == '#') {
		while (c != '\n') c = getchar();
		c = getchar();
	}
	return c;
}

/* 
 * Prints the ascii characters of an integer
 * http://www.geeksforgeeks.org/print-long-int-number-c-using-putchar/ 
 */
void writeAsciiOfPositiveInteger(int n) {
	if (n/10) writeAsciiOfPositiveInteger(n/10); // Remove the last digit recursevily
	putchar(n%10 + '0'); // Print the last digit 
}