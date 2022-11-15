/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 2 - Task 1, Task 2, Task 3

TASK 1:
The first task that you have to undertake is to set the width of the line for the new document. 
To do this you must read from an input .txt document where the settings of the document will be indicated on the first line.

NOTE: You will have to use ifstream for taking in the file and ofstream for generating the output file.

For example an input.txt will start with:

60;output.txt;
What is Lorem Ipsum?
Lorem Ipsum is simply dummy text of the printing and typesetting industry. 
Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, 
when an unknown printer took a galley of type and scrambled it to make a type specimen book.

Speaking of books, I love books. I read and write, sometimes at the same time because why not! Why should
I be limited by my measily brain and only do one task at a time? Exactly.

Well, thank you for listening. I appreciate you all :)

The number 60 on this case will indicate the max width of characters your output document will hold on every line. 
The second parameter should be the name of the output text file where your formatted document will be stored, which in 
this case it’s output.txt. Please keep in mind that each of the settings on the first line are seperated by a ; with no space in between.

Based on the example input file shown above, our output.txt should look something like this 
after running it through our amazing Word formatter:

$ ./word
$ Enter the input filename: input.txt

What is Lorem Ipsum?                                       
Lorem Ipsum is simply dummy text of the printing and       
typesetting industry. Lorem Ipsum has been the industry's  
standard dummy text ever since the 1500s, when an unknown  
printer took a galley of type and scrambled it to make a   
type specimen book.                                        

Speaking of books, I love books. I read and write,         
sometimes at the same time because why not! Why should I be
limited by my measily brain and only do one task at a time?
Exactly.                                                    

Well, thank you for listening. I appreciate you all :)

NOTE: Each paragraph, even though the amount of lines changed, stayed as their own paragraphs.


TASK 2:
Now we are given the task to add more functionality to our Word Application.

First is that we will now look for headers and body. Basically, if a line is in all uppercase, 
then it is a header/title/etc. The body is everything else. The significance will be explained after we discuss the next feature.

We will now add the ability to justify our input, which will contain three types: right, left and center. 
There will be two things you have to justify, the body and the headers.

If the user does not pass a justification for the body, then it should be defaulted to left.

If the user does not specify a justification for the headers, then it should be defaulted to whatever the body is justified to.

To have a better understanding of this lets look back at our previous example on Task 1. Now our input will take one more argument 
after the document size which will look something like this: 60;right;left;output.txt . This will indicate that the body of the document 
will be justified to the right and the headers to the left.

For example, our input.txt has:

60;right;left;output.txt;
WHAT IS LOREM IPSUM?
Lorem Ipsum is simply dummy text of the printing and typesetting industry.
Lorem Ipsum has been the industry's standard dummy text ever since the 1500s,
when an unknown printer took a galley of type and scrambled it to make a type specimen book.

Speaking of books, I love books. I read and write, sometimes at the same time because why not! Why should
I be limited by my measily brain and only do one task at a time? Exactly.

TITLE 2
Well, thank you for listening. I appreciate you all :)
Then it’s output.txt should look like:

WHAT IS LOREM IPSUM?                                       
       Lorem Ipsum is simply dummy text of the printing and
  typesetting industry. Lorem Ipsum has been the industry's
  standard dummy text ever since the 1500s, when an unknown
   printer took a galley of type and scrambled it to make a
                                        type specimen book.

         Speaking of books, I love books. I read and write,
sometimes at the same time because why not! Why should I be
limited by my measily brain and only do one task at a time?
                                                   Exactly.

TITLE 2                                                    
     Well, thank you for listening. I appreciate you all :)


TASK 3:
Now we have two more features that Microhard asked us to implement in the last minute and they are Double Space and Fill

As all of our previous settings, they will be included in the first line of the input.txt file where it will look something like this: 60;right;left;true;true;output.txt;. Both these settings are boolean values which will indicate weather a document uses fill / double space. The first boolean statement within the line will indicate weather the document contains the fill settings or not, the second is for double spaced.

By fill we mean filling up a line in the output before moving onto the next. For example, lets say the max width is 10 and the current line already has 5 characters. The next word that we are trying to fit is 10 characters long, we can only fit 3 characters of that word before moving the rest into the next line. ` Based on the given example, this line: Willy Strawberry
Would become: Willy Str- aberry

  
- Double spaced means that between each line there should be an extra empty line. The crux is that for titles, there should also be an extra empty line before it as well so as to space it out even more. Check out the Tasks example below.  
**Overall, the settings format should be:
`max_width;justify_body;justify_headers;to_fill;double_spaced;output_filename;`**. 

For example, our `input.txt` has:

60;center;center;true;true;output.txt;

WHAT IS LOREM IPSUM? Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry’s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.

Speaking of books, I love books. I read and write, sometimes at the same time because why not! Why should I be limited by my measily brain and only do one task at a time? Exactly.

TITLE 2 Well, thank you for listening. I appreciate you all :)



Would make the following `output.txt`:


               WHAT IS LOREM IPSUM?                   
Lorem Ipsum is simply dummy text of the printing and types-

etting industry. Lorem Ipsum has been the industry’s stand-

ard dummy text ever since the 1500s, when an unknown print-

er took a galley of type and scrambled it to make a type s-

pecimen book.

Speaking of books, I love books. I read and write, sometim-

es at the same time because why not! Why should I be limit-

ed by my measily brain and only do one task at a time? Exa-

ctly.

                      TITLE 2                          
Well, thank you for listening. I appreciate you all :)


---  
  
Also, if you are getting random `NULL` objects in your output file, you can utilize the following function that we've made to clean it up.  
  
```c++
/**
 * @brief Removes NULL characters from the given string
 * 
 * @param line 
 * @return std::string 
 * 
 * 
std::string removeNullChars(std::string line) {

    std::string null_less_line = "";

    for(int i = 0; i < line.length(); i++) {
        if(line[i] != '\0') {
            null_less_line += line[i];
        }
    }

    return null_less_line;
}
*/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string lineSplit(string line, int width) {
    string result = "";
    int count = 0;
    istringstream iss(line);
    string word;
    bool first = true;

    while(iss >> word) {
        int size = word.length() + 1;

        if(first == 1) {
            result += word;
            count += word.size();
            first = false;
        } else if(size + count < width) {
            result += " " + word;
            count += size;
        } else {
            result += "\n" + word;
            count = word.size();
        }
    }

    return result;
}

string resultOutput(ifstream &readFile, int count) {
    string result = "";
    string line;
    bool first = true;
    bool print = false;
    bool lineBreak = false;
    string paragraph = "";

    while(getline(readFile, line)) {
        paragraph += " " + line;

        if(line.size() <= count) {
            print = true;
            result += lineSplit(paragraph, count);

            if(line == "" && result[result.size() - 1] != '\n') {
                result += "\n";
            }

            result += "\n";
            paragraph = "";
        } else {
            print = false;
        }
    }

    if(print == 0) {
        result += lineSplit(paragraph, count);
    }

    if(result[result.size() - 1] == '\n'){
        return result.substr(0, result.size() - 1);
    }

    return result;
}

/*
void align(const string& input, string justify1, string justify2, int limit, string output) {
    istringstream iss(input);
    ofstream cout(output);

    for(string line; getline(iss, line);) {
        if(isupper(line[0]) && isupper(line[1])) {
            if(justify2 == "right") {
                cout.width(limit); 
                cout << right << line << endl;
            } else {
                cout.width(limit); 
                cout << left << line << endl;
            }
        } else if(justify1 == "right") {
            cout.width(limit); 
            cout << right << line << endl;
        } else {
            cout.width(limit); 
            cout << left << line << endl;
        }
    }
}
*/

// I HAVE NO IDEA HOW TO DO PROJECT 2 TASK 2
// I HAVE NO IDEA HOW TO DO PROJECT 2 TASK 3
int main() {
    string fileName;
    cout << "Enter the input filename: ";
    cin >> fileName;

    int limit;
    ifstream readFile, file;
    readFile.open(fileName);

    string firstLine;
    getline(readFile, firstLine);
    int index = firstLine.find(';');
    int count = stoi(firstLine.substr(0, index));
    string outputFile = firstLine.substr(index + 1, firstLine.size() - index - 2);

    string output = resultOutput(readFile, count);
    readFile.close();

    ofstream fileOut;
    fileOut.open(outputFile);
    fileOut << output;
    fileOut.close();

    return 0;
}