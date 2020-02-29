/*
  File Name: String.h
  Author: Spencer Peace
  Course: CSC 402-001
  Date: 02/29/2020
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
    // Move constructor
    String(String&&) noexcept ;
    int length() const { return strlen(str); } // one-line function to return the length of a string
    bool empty() const { return (strlen(str) == 0) ? true : false; } // one-line function to return if a string is empty or not
    void print(ostream& out = cout) const { out << this->str; } // one-line function to print the value of the buffer
    String& operator=(const String&); // overloaded "=" operator, copy operation
    String& operator=(const String&&) noexcept ; // overloaded "=" operator, move operation
    String& operator+(const String&); // overloaded "+" operator
    ~String() { delete[] str; } // implement destructor
    void clear();
    // implement append mutator functions
    String& append(const String&);
    String& append(const char*);
    const char& operator[](int) const; // overloaded method to return character at given index
    char& operator[](int); // overloaded method to set character at a given index
};

// overloaded << operator for handling output
ostream& operator<<(ostream&, const String&);

#endif //PROJECT2_STRING_H
