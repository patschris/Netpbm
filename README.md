# Netpbm
There are many formats used to encode an image. One of them is the Netpbm format (https://en.wikipedia.org/wiki/Netpbm_format). 
The netpbm formst supports rgb images (ppm), grayscale images (pgm) and black and white images (pbm). 
Netpbm uses a "magic" number to describr these images:
* P1 (B&W image in ascii format)
* P2 (grayscale image in ascii format)
* P3 (rgb image in ascii format)
* P4 (B&W image in binary format)
* P5 (grayscale image in binary format)
* P6 (rgb image in binary format)

This program supports the following convertions:
- P2 to P1
- P3 to P2
- P5 to P4
- P6 to P5

Execution command: ./netpbm < {input_image} > {output_image}

Written in C, Ubuntu 16.04.3 LTS. 
Contains makefile: `make` to compile and `make clean` to delete object files and executable.
In the folder "input", there are images to test the program.
