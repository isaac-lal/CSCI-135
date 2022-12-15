/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 12

Customer

Define class Customer, 
which as data member name and unique_id, 
both of string type. Define default and 
non-default constructor, setter, and getter.
*/

#include <iostream>
using namespace std;

class Customer {
private:
    string name; 
    string unique_id;
public:
    Customer();
    Customer(string name, string unique_id);
    string get_name();
    string get_unique_id();
    void set_name(string input_name);
    void set_unique_id(string input_unique_id);
};    

Customer::Customer() {
    name = "";
    unique_id = "";
}

Customer::Customer(string name, string unique_id) {
    this->name = name;
    this->unique_id = unique_id;
}

string Customer::get_name() {
    return name;
}

string Customer::get_unique_id() {
    return unique_id;
}

void Customer::set_name(string input_name) {
    name = input_name;
}

void Customer::set_unique_id(string input_unique_id) {
    unique_id = input_unique_id;
}

int main() {
    Customer a = {"Bob", "8"};

    cout << a.get_name() << " " << a.get_unique_id() << endl;

    Customer b;

    cout << b.get_name() << " " << b.get_unique_id() << endl;

    //test changing name
    string custb;
    cout << "Change name of b:" << endl;
    cin >> custb;

    b.set_name(custb);
    cout << b.get_name() << " " << b.get_unique_id() << endl;

    return 0;
}