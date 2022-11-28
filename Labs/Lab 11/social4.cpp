/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 11D

Write a new program social4.cpp, which is an improved version of the previous program.

The class Network should be changed to allow users post messages and remember them. You should:

(Outside the class Network), define a new struct:
struct Post{
  string username;
  string message;
};
In the class Network, add private variables:
private:
 static const int MAX_POSTS = 100;
 int numPosts;                    // number of posts
 Post posts[MAX_POSTS];           // array of all posts
Modify constructor Network so that it initializes numPosts to 0.

Add two functions in the public interface of the class:
public:
 // Add a new post
 bool writePost(string usrn, string msg);
 // Print user's "timeline"
 bool printTimeline(string usrn);
The first function,writePost(usrn, msg) adds a new post to the posts array. It performs successfully if the username is found in the network and the posts array is not full, in this case the function also should return true. Otherwise, nothing is added and the function returns false.

The second function, printTimeline(usrn) prints out the timeline of the user usrn. The timeline of a user is the list of all posts by the user and by the people they follow, presented in reverse-chronological order. They should be printed in the following format:

Displayname (@username): message
Displayname (@username): message
Displayname (@username): message
Displayname (@username): message
To summarize, the final version of the class Network and struct Post declarations:

struct Post{
    string username;
    string message;
};

class Network {
private:
    static const int MAX_USERS = 20;
    int numUsers; 
    Profile profiles[MAX_USERS];
    bool following[MAX_USERS][MAX_USERS];  
    static const int MAX_POSTS = 100;         // new
    int numPosts;                             // new
    Post posts[MAX_POSTS];                    // new
    int findID (string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2);
    void printDot(); 
    bool writePost(string usrn, string msg);  // new
    bool printTimeline(string usrn);          // new
};
A usage example
(When submitting your code, please use this exact main function):

int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}
It generates a small network of three users and prints out the timelines of two of them:

======= Mario's timeline =======
Mario (@mario): My crazy plans always work!
Luigi (@luigi): I just hope this crazy plan of yours works!
Mario (@mario): Hi Luigi!
Luigi (@luigi): Hey hey!
Mario (@mario): It's a-me, Mario!

======= Yoshi's timeline =======
Yoshi (@yoshi): Test 5
Yoshi (@yoshi): Test 4
Yoshi (@yoshi): Test 3
Mario (@mario): My crazy plans always work!
Yoshi (@yoshi): Test 2
Yoshi (@yoshi): Test 1
Mario (@mario): Hi Luigi!
Mario (@mario): It's a-me, Mario!

*/

#include <iostream>
#include <string>
using namespace std;

struct Post{
    string username;
    string message;
};

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
    static const int MAX_POSTS = 100;
    int numPosts;                    // number of posts
    Post posts[MAX_POSTS];           // array of all posts

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    bool following[MAX_USERS][MAX_USERS];    // friendship matrix:
    // following[id1][id2] == true when id1 is following id2
    int findID(string usrn);
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

    // Add a new post
    bool writePost(string usrn, string msg);
    // Print user's "timeline"
    bool printTimeline(string usrn);
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

/*
//TASK C
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
*/

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");
    
    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");

    // write some posts
    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");

    cout << endl;
    cout << "======= Mario's timeline =======" << endl;
    nw.printTimeline("mario");
    cout << endl;

    cout << "======= Yoshi's timeline =======" << endl;
    nw.printTimeline("yoshi");
    cout << endl;
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
    numPosts = 0;

    for(int max1 = 0; max1 < MAX_USERS; max1++) {
        for(int max2 = 0; max2 < MAX_USERS; max2++) {
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
    if(findID(usrn1) != -1 && findID(usrn2) != -1) {
        following[findID(usrn1)][findID(usrn2)] = true;

        return true;
    } else {
        return false;
    }
}

void Network::printDot() {
    cout << "digraph {" << endl;

    for(int i = 0; i < numUsers; i++) {
        cout << " " << "\"@" << profiles[i].getUsername() << "\"" << endl;
    } // retrieves usernames of all profiles within the class

    // retrieves the following of those profiles
    for(int i = 0; i < numUsers; i++) {
        for(int j = 0; j < numUsers; j++) {
            if(following[i][j] == true) {
                cout << " " << "\"@" << profiles[i].getUsername() << "\" -> \"@"
                     << profiles[j].getUsername() << "\"" << endl;
            }
        }
    }

    cout << "}" << endl;
}

bool Network::writePost(string usrn, string msg) {
    int index = findID(usrn);

    if(index == -1 || numPosts == MAX_POSTS) {
        return false;
    }

    posts[numPosts].username = usrn;
    posts[numPosts].message = msg;
    numPosts++;

    return true;
}

bool Network::printTimeline(string usrn) {
    int userIndex = findID(usrn);

    if(userIndex == -1) {
        return false;
    }

    for(int i = numPosts - 1; i >= 0; i--) {
        Post p = posts[i];
        int writeIndex = findID(p.username);

        if(p.username == usrn) {
            cout << profiles[userIndex].getFullName() << ": " << p.message << endl;
        } else if(following[userIndex][writeIndex]) {
            cout << profiles[writeIndex].getFullName() << ": " << p.message << endl;
        }
    }

    return true;
}