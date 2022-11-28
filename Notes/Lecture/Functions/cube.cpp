#include <iostream>
using namespace std;
/**
 Computes the volume of a cube.
 @param side_length the side length of the cube
 @return the volume
*/
double cube_volume(double side_length) {
   double volume = side_length * side_length * side_length;
   return volume;
}
int main() {
   double result1 = cube_volume(2);
   double result2 = cube_volume(10);
   cout << "A cube with side length 2 has volume "
   << result1 << endl;
   cout << "A cube with side length 10 has volume "
   << result2 << endl;
   return 0;
}