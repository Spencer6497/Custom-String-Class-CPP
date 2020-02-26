/*
  File Name: String.h
  Author: Spencer Peace
  Course: CSC 402-001
  Date: 02/26/2020
*/

#ifndef PROJECT2_STRING_H
#define PROJECT2_STRING_H

#include <cstring>
#include <iostream>

using namespace std;

class String {
private:
    char *str; // data member that holds string contents
public:
    // Constructor when passed a c-string variable (also no-arg constructor)
    explicit String(const char* string = "");
    // Constructor when passed a String as a source (copy constructor)
    String(const String&);
    int length() { return strlen(str); } // one-line function to return the length of a string
    bool empty() { return (strlen(str) == 0) ? true : false; } // one-line function to return if a string is empty or not
    void print(ostream& out = cout) { out << this->str; } // one-line function to print the value of the buffer
    String& operator=(const String& string) noexcept ; // overloaded "=" operator
    String& operator+(const String& string); // overloaded "+" operator
};

// overloaded << operator for handling output
ostream& operator<<(ostream&, String&);

#endif //PROJECT2_STRING_H
