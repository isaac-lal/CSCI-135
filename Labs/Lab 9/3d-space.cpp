/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 9A, 9B, 9C, 9E

TASK A:
A point in 3D space can be represented using three coordinates. In Cartesian coordinate system these coordinates are called (x,y,z), describing the position of the point along the three orthogonal axes:

The origin of the coordinate system is denoted by O and has coordinates (0,0,0).

A point P=(x,y,z), together with the origin, defines a 3D vector OP. The distance from O to P, or in other words, the length of the vector OP can be computed using the euclidean distance formula:

Length of the vector 
O
P
=
√
x
2
+
y
2
+
z
2
We are provided with a class type that represents coordinates in 3D:

class Coord3D {
public:
    double x;
    double y;
    double z;
};
Write a program 3d-space.cpp, in which you define a function length() that receives the coordinates of a point P passed as a pointer, and computes the distance from the origin to the point P:

double length(Coord3D *p);
A usage example:

int main() {
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl; // would print 37.4166
}
Notice that we pass the memory address &pointP, where the object of this class is located. The function should dereference this address to get the corresponding fields x, y, and z for computing the length.


TASK B:
In the same file 3d-space.cpp, add a function

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
Which receives the coordinates of two points (passed as pointers), and returns the pointer of the point that is farther away from the origin.

A usage example:

int main() {
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl; // So which point is farther?
}
When testing your code, look at the reported address of the answer ans and determine whether it reports P or Q. You can use a calculator or WolframAlpha) to check the numbers. Try other coordinates of points P and Q to confirm that the program works.


TASK C:
Let’s consider an object moving in 3D space. We already know how to describe its position. (We will be assuming metric system, thus distances will be implicitly measured in meters and time in seconds.)

The object’s velocity can be represented in the same 3D coordinate system as its displacement per second in the coordinates x, y, and z:

Coord3D vel = {5, -3, 1}; // x, y, z components of the velocity
When moving at constant velocity vel , the object’s new position after the elapsed time dt can be computed as

x' = x + vel.x * dt;

y' = y + vel.x * dt;

z' = z + vel.x * dt;
Let’s implement it. In the same program, write a function

void move(Coord3D *ppos, Coord3D *pvel, double dt);
which gets the position and the velocity of an object and has to compute object’s new coordinates after the time interval dt. The function does not return any values, instead, it should update the object’s position ppos with its new position coordinates.

Because we pass the coordinates Coord3D * ppos as a pointer, all changes to the fields of the class pointed by ppos, will affect the original object you pass into the function, not its local copy. Example:

int main() {
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); // object pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl;
    // prints: 2 -10 100.4
}
Notice that we are not passing anything by reference: We pass the address, &pos, and the function manipulates the original object pos, because it knows its address in the memory.

On dynamic memory allocation
Normally, any variable “lives” only within the block where it is declared, and disappears once the program execution leaves this scope. We know that already, right?

This memory management is called automatic, the program allocates memory for each variable when it enters the scope of the variable, and deletes that memory when leaving that scope.

A problem with automatic memory allocation:
The following function that’s supposed to create a poem and return its memory address, will not work (reliably):

string * createAPoem() {
    string poem =    // making a string with a poem 
      "   Said Hamlet to Ophelia,            \n"
      "   I'll draw a sketch of thee,        \n"
      "   What kind of pencil shall I use?   \n"
      "   2B or not 2B?                      \n";

    return &poem;    // and returning its address 
}
Since the variable poem exists only locally inside the function, after exiting the function, the memory allocated for this string gets claimed and freed by the program. Even though we returned the address where the poem was, after the function exits, that address may be taken and used by some other part of your program, the poem may be easily overwritten by some other value.

The keyword new
Question(?):
Can we allocate a chunk of memory for the poem so that it would remain persistent and would not be claimed by the program after the function exits?
Yes we can, using the keyword new:

string * createAPoemDynamically() {
    string *ppoem;      // declare a pointer to string
                        // (it will store the address)

    ppoem = new string; // <-- DYNAMICALLY ALLOCATE MEMORY
                        //     for a poem string and
                        //     store its address in the pointer

    *ppoem =            // put a poem there
      "   Those             \n"
      "   who can write     \n"
      "   have a            \n"
      "   lot to            \n"
      "   learn from those  \n"
      "   bright            \n"
      "   enough            \n"
      "   not to.           \n"; 

    return ppoem;       // return the address where the poem is
}
The address of a dynamically allocated memory can be passed around, returned from a function, or stored in another variable, etc.

The dynamically allocated memory will remain persistently in the computer memory throughout the program execution:

int main() {
    string * p;
    p = createAPoemDynamically();
    // The memory at the address p still stores the poem we
    // put in it during the function call. Neat!

    // At any later moment, you can print it out:
    cout << *p;

    // You can also save the address into another pointer variable:
    string *p2 = p;   // then both pointers, p and p2,
                      // will be pointing to the same poem.
    cout << *p2;
}
The keyword delete
Dynamically allocated memory is awesome, it stays persistently and does not depend on the variables and their life times. However, it also comes with problems: Once this memory is not needed, it must be manually released to the system, otherwise if we only keep allocating memory and never giving it back, we may run out of memory eventually.

When we know that we don’t need a dynamically allocated memory anymore, we have to delete it with keyword delete:

// allocate an integer dynamically
int *p = new int;
*p = 1234;          // we are using it
cout << *p << endl; //  ''  ''  ''  ''

// once it's not needed, delete it:
delete p;
Allocating arrays dynamically (operators new ... [] and delete[])
Dynamic memory allocation of arrays uses special operators with square brackets, we have to specify how many elements we want to get:

int n = 100; // how many elements we need
// Getting memory
string * lines = new string[n]; // array of 100 strings

lines[0] = "Roses are red";
lines[1] = "Violets are blue";

// ... Keep using the array ...

// Don't need it anymore - delete
delete[] lines;
When it is not needed, use operator delete[] to release the memory.


TASK E:
In the program 3d-space.cpp, add functions that create, delete, and coordinate objects dynamically:

// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z);

// free memory
void deleteCoord3D(Coord3D *p);
A usage example:

int main() {
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}
Expected output:

$ ./a.out
Enter position: 10 20 30
Enter velocity: 5.5 -1.4 7.77
Coordinates after 10 seconds: 65 6 107.7
*/

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};

// TASK A
double length(Coord3D *p) {
    double value = pow((*p).x, 2) + pow((*p).y, 2) + pow((*p).z, 2);

    return sqrt(value);
}

// TASK B
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
    if(length(p1) > length(p2)) {
        return p1;
    } else {
        return p2;
    }
}

// TASK C
void move(Coord3D *ppos, Coord3D *pve1, double dt) {
    ppos -> x += pve1 -> x * dt;
    ppos -> y += pve1 -> y * dt;
    ppos -> z += pve1 -> z * dt;
}

Coord3D * createCoord3D(double x, double y, double z) {
    Coord3D *p = new Coord3D();
    p -> x = x;
    p -> y = y;
    p -> z = z;

    return p;
}

// free memory
void deleteCoord3D(Coord3D *p) {
    delete p;
}

int main() {
    /*
    // TASK A: 
    Coord3D pointP = {10, 20, 30};

    cout << length(&pointP) << endl; // would print 37.4166
    return 0;
    */

    /*
    // TASK B: 
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};
    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl << endl;
    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl; // So which point is farther?

    return 0;
    */

    /*
    // TASK C:
    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};
    move(&pos, &vel, 2.0); // object pos gets changed

    cout << pos.x << " " << pos.y << " " << pos.z << endl;
    // prints: 2 -10 100.4

    return 0;
    */

    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);

    return 0;
}