/*
  File Name: String.h
  Author: Spencer Peace
  Course: CSC 402-001
  Date: 02/23/2020
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
    // Constructor when passed a c-string variable
    String(const char* string);
    // Constructor when passed a String as a source
    String(const String&);
    // Empty string constructor
    String();
    int length();
    bool empty();
    void print(ostream& out = cout);
};

// overloaded << operator for handling output
ostream& operator<<(ostream&, String&);

#endif //PROJECT2_STRING_H
