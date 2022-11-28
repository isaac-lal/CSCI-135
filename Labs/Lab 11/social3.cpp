/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 11C

Write a new program social3.cpp, which is an improved version of the previous program.

The class Network should be changed to keep the friendship (following) relation between the users. You should:

add one private variable:
private:
 bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
 // following[id1][id2] == true when id1 is following id2
An example demonstrating this friendship matrix for a small network of three users is shown below:

The constructor Network() should be modified, setting all elements of the matrix following to false, so in empty network no one is following anyone.

Add two functions to the public interface:
public:
 // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
 // return true if success (if both usernames exist), otherwise return false
 bool follow(string usrn1, string usrn2);

 // Print Dot file (graphical representation of the network)
 void printDot();
The first new function follow(usrn1, usrn2) simply marks the corresponding cell in the friendship matrix if both usernames are found. It returns true or false, depending on whether the operation was successful or not.

The second new function printDot() will be used to visualize the network. For that, make the function print out the network in the following format:

digraph {
  "@mario"
  "@luigi"
  "@yoshi"

  "@mario" -> "@luigi"
  "@luigi" -> "@mario"
  "@luigi" -> "@yoshi"
  "@yoshi" -> "@mario"
}
Here, we are listing usernames with @ and in quotes, followed by each of the friendship connections, each on its own line. The example above is the exact output the function should produce for the simple network of three users @mario, @luigi, and @yoshi provided previously.

This output format is called “Dot file format”, it can be used in the application Graphviz to generate a visual diagram of the network. We can use this Online Graphviz app: https://dreampuf.github.io/GraphvizOnline/. Paste the Dot output in the left pane, and you will get a picture in the right pane.

To summarize, the new modified class declaration should look as follows:

class Network {
private:
    static const int MAX_USERS = 20; 
    int numUsers;                    
    Profile profiles[MAX_USERS];     
    bool following[MAX_USERS][MAX_USERS];    // new 
    int findID (string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2); // new
    void printDot();                         // new
};
A usage example (it needs --std=c++11 flag to compile)
(When submitting your code, please use this exact main function):

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
A Graphviz visualization of the network produced by the example above:



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
    bool following[MAX_USERS][MAX_USERS];    // friendship matrix:
    // following[id1][id2] == true when id1 is following id2
    int findID (string usrn);
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);
    // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
    // return true if success (if both usernames exist), otherwise return false
    bool follow(string usrn1, string usrn2); // new

    // Print Dot file (graphical representation of the network)
    void printDot();                         // new
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

    // TASK B
    /*
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

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
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

    for (int max1 = 0; max1 < MAX_USERS; max1++) {
        for (int max2 = 0; max2 < MAX_USERS; max2++) {
            // the process sets all users following to false, or 0
            following[max1][max2] = false;
        }
    }
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

bool Network::follow(string usrn1, string usrn2) {
    if (findID(usrn1) != -1 && findID(usrn2) != -1) {
        following[findID(usrn1)][findID(usrn2)] = true;

        return true;
    } else {
        return false;
    }
}

void Network::printDot() {
    cout << "digraph {" << endl;

    for (int i = 0; i < numUsers; i++) {
        cout << " " << "\"@" << profiles[i].getUsername() << "\"" << endl;
    } // retrieves usernames of all profiles within the class

    // retrieves the following of those profiles
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numUsers; j++) {
            if (following[i][j] == true) {
                cout << " " << "\"@" << profiles[i].getUsername() << "\" -> \"@"
                     << profiles[j].getUsername() << "\"" << endl;
            }
        }
    }

    cout << "}" << endl;
}