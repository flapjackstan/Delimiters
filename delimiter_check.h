#pragma once
#include <iostream>
#include <fstream>

using namespace std;


/*
	A. Action: Returns delimiters opposite
	B. Arguement/s: Delimiter
*/
char Opposite(char delimiter);

/*
	A. Action: Checks if each open delimiter has a corresponding closing delimiter
	B. Arguement/s: Name of file to read from
*/
bool DelimiterCheck(string my_file);