#include <iostream>
#include <iomanip>
using namespace std;

class CashRegister {
public:
   void clear();
   void add_item(double price);
   double get_total() const;
   int get_count() const;
private:
   int item_count;
   double total_price;
};

void CashRegister::clear() {
   item_count = 0;
   total_price = 0;
}

void CashRegister::add_item(double price) {
   item_count++;
   total_price = total_price + price;
}

double CashRegister::get_total() const {
   return total_price; 
}

int CashRegister::get_count() const {
   return item_count; 
}

// NOT a member function: 
void display(CashRegister reg) {
   cout << "Item " << reg.get_count() << ": $"
      << fixed << setprecision(2) << reg.get_total() << endl;
}

int main() {
   CashRegister register1;
   CashRegister register2;
   register1.clear();
   register2.clear();
   register1.add_item(1.95);
   display(register1);
   register1.add_item(0.95);
   display(register1);
   register2.add_item(2.50);
   display(register2);
   register2.add_item(6.99);
   display(register2);
   return 0;
}