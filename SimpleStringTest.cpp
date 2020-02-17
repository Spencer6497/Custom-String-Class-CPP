#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <iostream>

using namespace std; 

int main()
{
	// a stack-allocated string that might be used for input
	char s[] = "test"; 
	cout << strlen(s) << endl;

	// heap-allocated string interacting with stack-allocated
	char* buf = new char[strlen(s) + 1]; 
	strcpy(buf, s);
	cout << strlen(buf) << endl;
	cout << buf << endl << endl; 
	
	delete[] buf;
	cout << "after delete" << endl;

	cin.get(); 
}