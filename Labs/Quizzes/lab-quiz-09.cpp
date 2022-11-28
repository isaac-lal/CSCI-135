/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 09

Checkboard Image

The output image has a checkboard pattern, alternating between
the image and black pixels

Submit ONLY cod ethat goes in the section 
// INSERT CODE HERE

Make sure syntax is 100% correct to fit in the designated area.
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
    readImage(img, h, w);

    int out[MAX_H][MAX_W];
    
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            // INSERT CODE HERE
            if(row % 2 == 0) { // if the row is even
                if(col % 2 == 0) { // and if the col is also even
                    out[row][col] = 0; // make pixel black
                } else {
                    out[row][col] = img[row][col]; // make pixel color of the image
                }
            } else if(row % 2 != 0) { // if the row is odd
                if(col % 2 == 0) { // and if the col is also even
                    out[row][col] = img[row][col]; // reverse the order
                } else { 
                    out[row][col] = 0; 
                }
            }
        }
    }

    writeImage(out, h, w);
	
    return 0;
}