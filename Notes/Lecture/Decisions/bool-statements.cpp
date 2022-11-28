// Example program
#include <iostream>
#include <string>

int main()
{
    bool name; 
    int n = 5, k = 2;
    
    name = !(n >= 0 && n <= k);
    std::cout << "!(n >= 0 && n <= k) is " << name << " \n\n";
    
    name = n < 0 || n > k;
    std::cout << "n < 0 || n > k is " << name << " \n\n\n";


    name = !(n >= 0 && n >= k);
    std::cout << "!(n >= 0 && n >= k) is " << name << " \n\n";
    
    name = n < 0 || n < k;
    std::cout << "n < 0 || n < k is " << name << " \n\n";
}