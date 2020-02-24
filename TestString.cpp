/*
  File Name: TestString.cpp
  Author: Spencer Peace
  Course: CSC 402-001
  Date: 02/23/2020
*/

// Visual Studio-specific deirective to suppress warnings
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

// your file must be named String.h
#include "String.h"

using namespace std;

int main() {


  /* 
    =================== README ======================================
    You may have to start with parts of main commented out.  
    As you add constructors and other functions, simply move the 
	comment block characters to allow more of main to run.
	In your submitted version, all of it should run. 
	===================================================================
  */


  // single and no-arg constructor tests
  String str1;
  String str2("constructed with a c-string literal");
  const char* c_str { "constructed with a c-string variable" };
  String str3(c_str);
  // intializer list syntax  
  String str4 { "I am str4" };

  String str5 { "str5 as the source of a copy" }; 
  // copy constructor
  String str6(str5);


  // copy = operator
  String str7; 
  str7 = str6; 

  // move constructor
  String tmp_str1{ "Source of move constructor" };
  String str8(std::move(tmp_str1));

  // move = operator
  String tmp_str2{ "Source of move = operator" };
  String str9;  
  str9 = std::move(tmp_str2);


  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "str3: " << str3 << endl;
  cout << "str4: " << str4 << endl;
  cout << "str5: " << str5 << endl;
  cout << endl;


  cout << "str6 and str7 are both copies of str5: " << endl;
  cout << "str6: " << str6 << endl;
  cout << "str7: " << str7 << endl;
  cout << endl; 
/*
  cout << "str8 stole the contents of tmp_str1: " << endl; 
  cout << "str8: " << str8 << endl;
  cout << "str9 stole the contents of tmp_str2: " << endl;
  cout << "str9: " << str9 << endl;
  cout << endl;

  // to test that these objects are invalid, uncomment these statements
  //cout << tmp_str1 << endl; 
  //cout << tmp_str2 << endl; 


  */
  cin.get();
  return 0; 
}
