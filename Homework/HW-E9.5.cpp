/* 
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E8.1

Implement a class Rectangle. 
Provide a constructor to construct a rectangle 
with a given width and height, member functions 
get_perimeter and get_area that compute the perimeter 
and area, and a member function void resize(double factor) 
that resizes the rectangle by multiplying the width 
and height by the given factor.
*/

#include <iostream>

class Rectangle {
public:
    Rectangle(double input_w, double input_h);
    double get_perimeter();
    double get_area();
    void resize(double factor);
private:
    double width = 0;
    double height = 0;
};

Rectangle::Rectangle(double input_w, double input_h) {  
    width = input_w;
    height = input_h;
}

double Rectangle::get_perimeter() {
    return(2 * width + 2 * height);
}

double Rectangle::get_area() {
    return(width * height);
}

void Rectangle::resize(double factor) {
    width *= factor;
    height *= factor;  
}

int main() {
    Rectangle r = {2, 4};
      
    std::cout << "Perimeter is " << r.get_perimeter() << "\n";
    std::cout << "Area is " << r.get_area() << "\n";

    r.resize(3);

    std::cout << "Perimeter is " << r.get_perimeter() << "\n";
    std::cout << "Area is " << r.get_area() << "\n";
}