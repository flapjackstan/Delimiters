/*
  a. Name: Elmer Camargo
  b. Student ID: 2291367
  c. Chapman email: camargop@chapman.edu
  d. Course number and section: 350-02
  e. Assignment Number: 3 - Delimiter Check 
*/

#include <iostream>
#include<string>
#include "delimiter_check.h"

using namespace std;

string file_name;
int decision = 1;

int main(int argc, char const* argv[])
{
	file_name = argv[1];

	while(decision == 1)
	{
		if(DelimiterCheck(file_name))
		{
			cout<<"\nYour file is valid\n";
			cout<<"\nWould you like to process another file?\t1 for yes, 0 for no\n";
			cin>> decision;

			if(decision == 1)
			{
				cout << "\nPlease enter the name of the file you would like to process: ";
				cin >> file_name;
			}
		}

		else
		{
			cout<<"\nPlease Fix Error\n";
			return 0;
		}
	}
}

