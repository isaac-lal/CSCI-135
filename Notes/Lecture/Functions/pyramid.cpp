#include <iostream>
using namespace std;
/** Computes the volume of a pyramid whose base is a square.
 @param height the height of the pyramid
 @param base_length length of one side of the pyramid’s base
 @return the volume of the pyramid
*/
double pyramid_volume(double height, double base_length)
{
 double base_area = base_length * base_length;
 return height * base_area / 3;
}
int main()
{
 cout << "Volume: " << pyramid_volume(9, 10) << endl;
 cout << "Expected: 300" << endl << endl;
 cout << "Volume: " << pyramid_volume(0, 10) << endl;
 cout << "Expected: 0" << endl;
 return 0;
}