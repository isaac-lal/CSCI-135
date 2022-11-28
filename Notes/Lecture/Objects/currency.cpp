#include <iostream>
#include <iomanip>
using namespace std;

class Currency {
public:
  float exchange_rate;
  char currency_sign;
};

class Money_transfer {
public:
  float amount;
  Currency *c;
};

void print_amount (Money_transfer t) {
  cout << setprecision(2) << fixed << t.amount * t.c->exchange_rate << t.c->currency_sign << endl;
}

int main () { 
  Currency c;
  c.exchange_rate = 1.05;
  c.currency_sign = 'E';
  
  Money_transfer transfer_one;
  transfer_one.amount = 47; // $47
  transfer_one.c = &c;
  
  Money_transfer transfer_two;
  transfer_two.amount = 34; // $37
  transfer_two.c = &c;
  
  cout << "First transfer: ";
  print_amount (transfer_one);
    
  cout << "Second transfer: ";
  print_amount (transfer_two); 
  
  c.exchange_rate = 1.23;

  cout << "After the exchange rate changes: \n";

  cout << "First transfer: ";
  print_amount (transfer_one);

  cout << "Second transfer: ";
  print_amount (transfer_two);

  return 0;
}