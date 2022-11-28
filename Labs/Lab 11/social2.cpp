/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 11B

The three main functionalities of the class Network are: 1) adding new users to the network, 2) following, and 3) posting messages. We are going to develop them in these three tasks.

Write a program social2.cpp, implementing the first version of the class Network (feel free to copy your class Profile and anything else from the previous program).

This first version of the class should be able to add new users and store their profiles, for that, the class has the following private variables:

an array of registered user profiles,
an integer numUsers, which stores the number of registered users.
the size of the profiles array is defined as MAX_USERS=20, we cannot sign up more than this number of users.
The index in the array profile is the profile ID. As you keep adding new users, they are receiving ID = 0, 1, 2, and so on. To look up the ID of a specific profile by its username, we have a private function findID(usrn), it should return the ID of the user with that username, or -1 if the user is not found in the profiles array.

The public interface:

a default constructor that creates an empty network. For now, setting numUsers = 0 is enough.
addUser(usrn, dspn) is the central function for the class. It allows adding new users. This function receives the username and display name of a new user, the new user can be signed up only if the following conditions are met:
the new username usrn must be a non-empty alphanumeric string,
there is no other users in the network with the same username,
the array profiles is not full.
If the above conditions are met, the new user should be added to the array profiles and the function should return true, otherwise don’t add the user and return false, thus indicating that the operation failed.

The full class declaration is shown below:

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
};
A usage example (it needs --std=c++11 flag to compile)
(When submitting your code, please use this exact main function):

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}
*/

#include <iostream>
#include <string>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};

class Network {
private:
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID (string usrn);
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);
};
    /*
    // TASK A:
int main() {
    Profile p1("marco", "Marco");

    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)

    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}
    */

int main() {
    Network nw;
    cout << nw.addUser("mario", "Mario") << endl;     // true (1)
    cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

    cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

    for(int i = 2; i < 20; i++)
        cout << nw.addUser("mario" + to_string(i), 
                "Mario" + to_string(i)) << endl;   // true (1)

    cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}

Profile::Profile(string usrn, string dspn){
    username = usrn;
    displayname = dspn;
}

Profile::Profile(){
    username="";
    displayname="";
}

string Profile::getUsername(){
    return username;
}

string Profile::getFullName(){
    string tempU = " (@" + username + ")";
    string x = displayname+ tempU;
    return x;
}

void Profile::setDisplayName(string dspn){
    displayname = dspn;
}

int Network::findID(string usrn) {
    int userid = -1;

    for(int i = 0; i <= numUsers; i++) {
        if(profiles[i].getUsername() == usrn) {
            return i;
        }
    }

    return userid;
}

Network::Network() {
    numUsers = 0;
}

bool Network::addUser(string usrn, string dspn) {
    if(numUsers < MAX_USERS && findID(usrn) == -1) {
        for(int j = 0;j < usrn.length();j++){
            if (!isdigit(usrn[j]) && !isalpha(usrn[j])) {
                return false;
            }
        }
        
        Profile adding(usrn, dspn);
        profiles[numUsers] = adding;
        numUsers++;

        return true;
    } else {
      return false;
    }
}