#include <iostream>
using namespace std;

void incrementAndPrint();
void incrementAndPrintS();
int generateID();
  
int main() { 
    for (int i = 0; i < 5; i++) {
      int id = generateID();
      cout << id << endl;
    }
    //incrementAndPrint();
    //incrementAndPrint();
    //incrementAndPrint();
}

void incrementAndPrint()
{
    int value = 1; // automatic duration
    ++value;
    cout << value << '\n';
} // value is destroyed here 

void incrementAndPrintS() {
    static int s_value = 1; // static duration
    ++s_value;
    cout << s_value << '\n'; 
   // s_value is not destroyed here, but becomes inaccessible
}

int generateID() {
   static int s_itemID = 0;
   return s_itemID++; 
} //returns new value and increments itemID