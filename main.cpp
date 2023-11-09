// Program: Operations on String Type Class Using Pointers
// Programmer: M Maaz Ahmad
// Compiler: Microsoft Visual Studio 2022 Community Edition

#include <iostream>
#include <string>
#include "myString.h"
using namespace std;

// tester
int main() {
    int ch, index;
    string s, sStr;
    myString s1, s2, s3;
    myString* s1ptr, * s2ptr, * s3ptr;
    s1ptr = &s1;
    s2ptr = &s2;
    s3ptr = &s3;
    do {
        cout << "===========================================" << endl
            << "---------------- * Menu * ----------------" << endl
            << "1. Insert 1st string" << endl
            << "2. Insert 2nd string" << endl
            << "3. Display both Strings" << endl
            << "4. Show Length of both strings" << endl
            << "5. Concatenate Strings" << endl
            << "6. Delete String" << endl
            << "7. Search String" << endl
            << "8. Compare Strings" << endl
            << "9. Exit" << endl
            << "===============================" << endl;

        while (cout << "Enter the option: " && !(cin >> ch)) {
            cin.clear(); //clear bad input flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "Invalid input; please re-enter.\n";
        }
        // Start: Switch
        switch (ch) {
        case 1:
            cout << "String 1: " << endl;
            strCreator(s1ptr, s);
            break;
        case 2:
            cout << "String 2: " << endl;
            strCreator(s2ptr, s);
            break;
        case 3:
            // checking if string is empty or not
            if (s1ptr->strCheck() && s2ptr->strCheck()) {
                cout << "String 1: ";
                strDisplay(s1ptr, s);
                cout << "String 2: ";
                strDisplay(s2ptr, s);
            }
            else
                cout << "No string entered! Please enter strings";
            break;
        case 4:
            if (s1ptr->strCheck() && s2ptr->strCheck()) {
                cout << "The length of 1st string is: " << stringLength(s1ptr) << endl;
                cout << "The length of 2st string is: " << stringLength(s2ptr) << endl;
            }
            else
                cout << "Strings are empty!";
            break;
        case 5:
            if (s1ptr->strCheck() && s2ptr->strCheck()) {
                s3 = s1 + s2;
                strDisplay(s3ptr, s);
            }
            else
                cout << "Strings are empty!" << endl;
            break;
        case 6:
            s3 = s3 - s2;
            cout << "After the deletion: \n";
            strDisplay(s3ptr, s);
            break;
        case 7:
            if (s3ptr->strCheck()) {
                cout << "Enter a string you want to find: ";
                cin.ignore();
                getline(cin, sStr);
                index = s3ptr->search(sStr);

                if (index == -1)
                    cout << "Result not found." << endl;
                else
                    cout << "Result found at index: " << index << endl;
            }
            else {
                cout << "Strings are not concatenated";
            }
            break;
        case 8:
            if (s1ptr->strCheck() && s2ptr->strCheck()) {
                if (s1ptr->getStr() > s2ptr->getStr())
                    cout << "String 1 is greater than String 2" << endl;
                else
                    cout << "String 2 is greater than String 1" << endl;
            }
            else {
                cout << "Strings not found! Enter strings";
            }
            break;
        case 9:
            exit(-1);
            break;
        default:
            cout << "Invalid Option!";
        }
        // End: Switch
    } while (true);

}
