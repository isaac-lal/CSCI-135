#include<iostream>
#include<string>
using namespace std;
class Counter {
public:
  void reset();
  void count();
  int get_value() const;
private:
  int value;
}; 
void Counter::count() {
  value++;
}
void Counter::reset() {
  value = 0;
}
int Counter::get_value() const {
  return value;
}
int main() {
  Counter tally;
  tally.reset();
  tally.count();
  tally.count();
  int result = tally.get_value();
  cout << "Value of tally: " << result << endl;
  tally.count();
  tally.count();
  result = tally.get_value();
  cout << "Value of tally: " << result << endl;
  
  Counter concert_counter;
  concert_counter.reset();
  concert_counter.count();
  concert_counter.count();
  concert_counter.count();
  result = concert_counter.get_value();
  cout << "Value of concert_counter: " << result << endl;
  return 0;
}