#include <iostream>
using namespace std;

void powers(double x, double& square, double& cube)
{
  square = x * x;
  cube = square * x;
  cout << square;
  cout << cube;
} 

int main() {
  double x = 2;
  double square = 0;
  double cube = 0;
  powers(x, square, cube);
  return 0;
}