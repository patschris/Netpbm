/*
 * Convert rgb pixel to grayscale pixel
 */
int rgbToGrayscale (int r, int g, int b) { 
	return ((299*r + 587*g + 114*b) / 1000);
}

/* Metatropi grayscale pixel se black/white */
int grayscaleToBW (int pixel, int max) {
	if (pixel > (max+1)/2) return 0;
	else return 1;
}