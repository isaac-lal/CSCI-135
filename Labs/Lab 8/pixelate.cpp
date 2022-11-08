/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 8F

Program pixelate.cpp will be pixelating the input image.

Example:

 
One way to pixelate an image is to effectively make every 2x2 non-overlapping window contain the same value (averaged over all the pixels in that window of the input). For example, the following image:

10 20 30 40
11 21 31 41
12 22 32 42
13 23 33 43
should be transformed to:

16 16 36 36
16 16 36 36
18 18 37 37
18 18 37 37
where the 16 was computed by averaging 10, 20, 11, and 21 (after rounding), and so on.

For simplicity, assume that the width and the height of the image are even numbers, so the picture is divisible into small 2x2 squares, like in the example above.
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
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
    int h, w;

    readImage(img, h, w); // read it from the file "inImage.pgm"
    // h and w were passed by reference and
    // now contain the dimensions of the picture
    // and the 2-dimesional array img contains the image data

    // Now we can manipulate the image the way we like
    // for example we copy its contents into a new array
    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if(row % 2 == 0) {
                if(col % 2 == 0) {
                    out[row][col] = (img[row][col] + img[row + 1][col] + img[row][col + 1] + img[row + 1][col + 1]) / 4;
                } else {
                    out[row][col] = (img[row][col] + img[row + 1][col] + img[row][col - 1] + img[row + 1][col - 1]) / 4;
                }
            } else {
                if (col % 2 == 0) {
                    out[row][col] = (img[row][col] + img[row - 1][col] + img[row - 1][col + 1] + img[row][col + 1]) / 4;
                } else {
                    out[row][col] = (img[row][col] + img[row - 1][col] + img[row][col - 1] + img[row - 1][col - 1]) / 4;
                }
            }
        }
    }

    // and save this new image to file "outImage.pgm"
    writeImage(out, h, w);
}