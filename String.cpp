/*
  File Name: String.cpp
  Author: Spencer Peace
  Course: CSC 402-001
  Date: 02/29/2020
*/

#include "String.h"

using namespace std;

// String constructor given a c-string variable (or no arguments, default is set in header)
String::String(const char* string) {
    str = new char[strlen(string) + 1]; //save to data member + space for \0
    strcpy(str, string); // archaic copy of string to data member
}

// Constructor for a string given another string's value (copy constructor)
String::String(const String &source){
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

// Constructor for a string given stealing another string's value (move constructor)
String::String(String&& stealString) noexcept {
    str = new char[strlen(stealString.str) + 1];
    strcpy(str, stealString.str);
    stealString.str = nullptr;
}

// Overloaded "=" operator (copy operation)
String& String::operator= (const String& stringToAssign) {
    delete[] str; // Clear the buffer
    str = new char[strlen(stringToAssign.str) + 1]; // Make room for the new string
    strcpy(str, stringToAssign.str); // Copy it
    return *this;
}

// Overloaded "=" operator (move operation).
String& String::operator=(const String&& string) noexcept {
    if (this != &string) {
        delete[] this->str;
        this->str = new char[strlen(string.str) + 1];
        strcpy(this->str, string.str);
    }
    return *this;
}

// Implement clear method
void String::clear() {
    delete[] str;
    str = new char[1]{*""};
}

// Implement append mutator functions
String& String::append(const String &str) {
    // create temp variable which will become the new buffer
    char *temp = new char[strlen(this->str)];
    strcpy(temp, this->str);
    delete[] this->str;
    this->str = temp;
    strcat(this->str, str.str);
    return *this;
}

String& String::append(const char *s) {
    char *temp = new char[strlen(s)];
    strcpy(temp, this->str);
    delete[] this->str;
    this->str = temp;
    strcat(this->str, s);
    return *this;
}

// Overloaded "+" operator such that it appends the string without changing the original or argument
String& String::operator+(const String& rhs) {
    char *temp = new char[strlen(rhs.str)];
    strcpy(temp, this->str);
    strcat(temp, rhs.str);
    return *new String(temp);
}

// Overloaded [] operator to return a character at a given index
const char& String::operator[](int index) const {
    return str[index];
}

// Overloaded [] operator to set a character at a given index
char& String::operator[](int index) {
    return str[index];
}

ostream& operator<<(ostream& out, const String& print) {
    print.print(out);
    return out;
}