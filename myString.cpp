#include "myString.h"

#include <iostream>
#include <string>
using namespace std;


string& myString::access() {
	// returns str address
	return str;
}

// finds string length
int myString::strLength() {
	return str.size();
}

bool myString::strCheck() {
	if (!(str.empty())) {
		return true;
	}
	else
		return false;
}

// concatenates s1 & s2 and stores it in s3
myString myString::operator+(const myString& obj) {
	myString temp;
	temp.str = str + " " + obj.str;
	return temp;
}

// deletes s2 from s3 and stores it in s3
myString myString::operator-(const myString& t) {
	myString temp;
	// temp = str - t.str;
	string dStr = str;
	string tDstr = (t.str);
	int i = dStr.find(tDstr);   // s3.find(s2)
	int l = tDstr.length();     // s2.length()
	temp.str = str.erase(i, l); // s3.erase(i, l)
	return temp;
}

// search a string
// takes a string and searches it in s3 str

int myString::search(string sStr) {
	string dStr = str;
	int i = dStr.find(sStr);
	// return the index of i
	return i;
}

//// get string from the object
string myString::getStr() {
	return str;
}

//// ------------------------------------------ //

// function for getting string from the user
void strCreator(myString *obj, string& s) {
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume any remaining input
	cout << "Enter the string: ";
	getline(cin, s);
	// using access member on the LHS of the assignment operator
	obj->access() = s;
	cout << endl;
}

void strDisplay(myString *obj, string s) {
	// using access memeber on the RHS of assignment operator
	s = obj->access();
	cout << s << endl;
}

int stringLength(myString *obj) {
	int sLength;
	// get length of the string and store in sLength
	sLength = obj->strLength();
	return sLength;
}
