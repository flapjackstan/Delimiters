#include <iostream>
#include <fstream>
#include <string>
#include "delimiter_check.h"
#include "GenStack.h"

using namespace std;

/*	
	A. Action: Reads a filename and converts contents from within that file into a string
	B. Arguement/s: Name of file to read from
*/
char Opposite(char delimiter)
{
	if(delimiter == '(') {return ')';}

	else if(delimiter == '{') {return '}';}

	else if(delimiter == '[') {return ']';}
}

/*	
	A. Action: Reads a filename and converts contents from within that file into a string
	B. Arguement/s: Name of file to read from
*/
bool DelimiterCheck(string my_file)
{
	char letter;
	char opposite;
	int count = 0;
	string temp;
	ifstream inFileStream;
	GenStack <char> open_stack = GenStack <char> (100);
	inFileStream.open(my_file);

	while (!inFileStream.eof()) 
	{
		getline(inFileStream, temp);
		count++;

		for(int i = 0; i<=temp.size()-1; i++)
		{
			letter = temp[i];
			if(letter == '(' || letter == '{' || letter == '[')

			{
				open_stack.push(letter);
			}

			else if(letter == ')' || letter == '}' || letter == ']')
			{
				if(open_stack.isEmpty())
				{
					cout << "\nError in line:" << count << "\nExtra closing delimiter in file\n"; 
					inFileStream.close();
					return false;
				}

				if(Opposite(open_stack.peek()) != letter)
				{
					inFileStream.close();
					cout << "\nError in line:" << count << "\nExpected: " << Opposite(open_stack.peek()) <<"\n"; 
					return false;
				}
				open_stack.pop();
			}
		}
	}



	if(open_stack.isEmpty())
		{
			inFileStream.close();
			return true;
		}
	else
	{
		cout << "\nError in line:" << count << "\nExpected: " << Opposite(open_stack.peek()) <<"\n"; 
		inFileStream.close();
		return false;
	}
}

