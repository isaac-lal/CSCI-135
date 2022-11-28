#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int TRIES = 100000; //can increase TRIES for more accuracy
    srand(time(0));
    int hits = 0;
    for (int i = 1; i <= TRIES; i++)
    {
        double r = rand() * 1.0 / RAND_MAX; // Between 0 and 1
        double x = -1 + 2 * r; // x in range –1 to 1
        r = rand() * 1.0 / RAND_MAX; //rand value for y
        double y = -1 + 2 * r;
        if (x * x + y * y <= 1) //hit inside circle
        { 
            hits++; 
        }
    }
    double pi_estimate = 4.0 * hits / TRIES;
    cout << "Estimate for pi: " << pi_estimate << endl;
    return 0;
} 