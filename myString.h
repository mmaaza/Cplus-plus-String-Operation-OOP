#pragma once
#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <string>
using namespace std;

// Start: myString class
class myString
{
	string str;

public:
	// myString class constructor
	myString() : str("") {}

	string& access();    // working as setter as well as getter
	int strLength();
	bool strCheck();
	myString operator+(const myString& obj);
	myString operator-(const myString& obj);
	int search(string sStr);
	string getStr();

};
// End: myString Class

void strCreator(myString* obj, string& s);
void strDisplay(myString* obj, string s);
int stringLength(myString* obj);
#endif
