/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 8G

A sliding window operator replaces each pixel with some function of its 8 neighbors (and itself). Consider pixel e and its 8 neighbors (labeled a-i) that form a 3x3 window around it:

. . . . . .
. . . . . .
. a b c . . 
. d e f . .
. g h i . .
. . . . . .
The operation replaces pixel e (in the middle of the 3x3 window) with some function of its neighbors f(a,b,c,d,e,f,g,h,i). It is possible to implement blur, edge detection, and many other image processing operations using this technique.

References:

Lode’s Computer Graphics Tutorial - Image Filtering
Interactive demo for different functions (kernels)
For this task, write a program kernel.cpp, which implements a horizontal edge detection operation. One way to detect horizontal edges is to use the function

f(a,b,c,d,e,f,g,h,i) = (g+2h+i)-(a+2b+c)
(This is one component of the so called Sobel operator, if you want to read more about it.)

Example:

 
Remark 1: Note that this is a sliding window operator unlike the non-overlapping window pixelization operator in the previous task. That is, the considered window is always a window around the pixel whose value is being computed.

Remark 2: You shouldn’t overwrite the original array. Make a new array for the output, and write the resulting pixel color into the new array.

Remark 3: There are several ways to handle the pixels on the borders, which don’t have all 8 neighbors available. Come up with any reasonable way to assign their colors (you can assume that the non-existing neighbors are black, or make the boundary wrap around, or even simply assign black color to the boundary pixels in the output).

Remark 4: If the resulting color is less than 0 or greater than 255, make them 0 and 255 respectively, otherwise writeImage function will complain that the colors are out of range.
*/


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

int main() {

    int img[MAX_H][MAX_W];
    int H, W;

    readImage(img, H, W); // read it from the file "inImage.pgm"
    // h and w were passed by reference and
    // now contain the dimensions of the picture
    // and the 2-dimesional array img contains the image data

    // Now we can manipulate the image the way we like
    // for example we copy its contents into a new array
    int out[MAX_H][MAX_W];

    //i am assuming neighbours that are not present to be black
    //create a temp matrix initialised as black(0) with size 1 more on each edges
    int temp[MAX_H+2][MAX_W+2];
    memset(temp,0,sizeof(temp));    //initialise with 0

    //copy original image into temp image
    for(int row = 0; row < H; row++) {
        for(int col = 0; col < W; col++) {
                temp[row+1][col+1] = img[row][col]; //skipping first row and first column of temp image
        }
    }

    int a,b,c,d,e,f,g,h,i;
    int func;

    for(int row =1; row<H+1; row++) {
        for(int col=1; col<W+1; col++) {
            a = temp[row-1][col-1];
            b = temp[row-1][col];
            c = temp[row-1][col+1];

            //no use of d,e,f
            g = temp[row+1][col-1];
            h = temp[row+1][col];
            i = temp[row+1][col+1];

            func = (g+2*h+i)-(a+2*b+c);

            if(func<0) {
                func=0;
            } 

            if(func>255) {
                func=255;
            }

            //put it in output image at its correct position

            out[row-1][col-1] = func;
        }
    }

    // and save this new image to file "outImage.pgm"
    writeImage(out, H, W);
}