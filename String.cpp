/*
  File Name: String.cpp
  Author: Spencer Peace
  Course: CSC 402-001
  Date: 02/23/2020
*/

#include "String.h"

using namespace std;

// String constructor given a c-string variable (or no arguments, default is set in header)
String::String(const char* string) {
    str = new char[strlen(string) + 1]; //save to data member + space for \0
    strcpy(str, string); // archaic copy of string to data member
}

// Constructor for a string given another string's value
String::String(const String &source){
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

// Function that returns number of characters in the string
int String::length() {
    return strlen(str);
}

bool String::empty() {
    return (strlen(str) == 0) ? true : false;
}

void String::print(ostream& out) {
    out << this->str;
}

ostream& operator<<(ostream& out, String& print) {
    print.print(out);
    return out;
}