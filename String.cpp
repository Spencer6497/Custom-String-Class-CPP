/*
  File Name: String.cpp
  Author: Spencer Peace
  Course: CSC 402-001
  Date: 02/26/2020
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

// Overloaded "=" operator
String& String::operator= (const String& stringToAssign) noexcept {
    if (this != &stringToAssign) {
        delete[] str; // Clear the buffer
        str = new char[strlen(stringToAssign.str) + 1]; // Make room for the new string
        strcpy(str, stringToAssign.str); // Copy it
    }
    return *this;
}

// Overloaded "+" operator
String& String::operator+(const String& rhs) {
    // TODO fill out this function
}

ostream& operator<<(ostream& out, String& print) {
    print.print(out);
    return out;
}