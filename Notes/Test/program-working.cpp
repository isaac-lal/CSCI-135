// Name: Isaac Lal

#include <iostream>
using namespace std;

int main() {
    cout << "Hey there!\n" << endl;

    int num1, num2, num3;
    string answer;

    cout <<"Please enter your first number of choice: ";
    cin >> num1;
    cout << "Please enter your second number of choice: ";
    cin >> num2;
    cout << "Please enter your third number of choice: ";
    cin >> num3;

    if(num1 > num2 && num1 > num3) {
        cout << "\nIs the greatest number of the three: " << num1 << "? (Yes/No): ";
        cin >> answer;

        if(answer == "Yes") {
            cout << "\nYay, the program works!";
        } else if(answer == "No") {
            cout << "\nThis program sucks :(";
        } else {
            while(answer != "Yes" || answer != "No") {
                cout << "That is not a \"Yes\" or \"No\" answer, please try again: ";

                cout << "\nIs the greatest number of the three: " << num1 << "? (Yes/No): ";
                cin >> answer;

                if(answer == "Yes") {
                    cout << "\nYay, the program works!";
                    break;
                } else if(answer == "No") {
                    cout << "\nThis program sucks :(";
                    break;
                }
            }
        }
    } else if(num2 > num1 && num2 > num3) {
        cout << "Is the greatest number of the three: " << num2 << "? (Yes/No): ";
        cin >> answer;

        if(answer == "Yes") {
            cout << "\nYay, the program works!";
        } else if(answer == "No") {
            cout << "\nThis program sucks :(";
        } else {
            while(answer != "Yes" || answer != "No") {
                cout << "That is not a \"Yes\" or \"No\" answer, please try again: ";

                cout << "\nIs the greatest number of the three: " << num2 << "? (Yes/No): ";
                cin >> answer;

                if(answer == "Yes") {
                    cout << "\nYay, the program works!";
                    break;
                } else if(answer == "No") {
                    cout << "\nThis program sucks :(";
                    break;
                }
            }
        }
    } else if(num3 > num1 && num3 > num2) {
        cout << "\nIs the greatest number of the three: " << num3 << "? (Yes/No): ";
        cin >> answer;

        if(answer == "Yes") {
            cout << "\nYay, this program works!";
        } else if(answer == "No") {
            cout << "\nThis program sucks :(";
        } else {
            while(answer != "Yes" || answer != "No") {
                cout << "That is not a \"Yes\" or \"No\" answer, please try again: ";

                cout << "\nIs the greatest number of the three: " << num1 << "? (Yes/No): ";
                cin >> answer;

                if(answer == "Yes") {
                    cout << "\nYay, the program works!";
                    break;
                } else if(answer == "No") {
                    cout << "\nThis program sucks :(";
                    break;
                }
            }
        }
    }
    return 0;
}