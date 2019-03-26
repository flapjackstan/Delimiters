#include <iostream>
#include <string>


using namespace std; 

class Exceptions
{
public:
	string errorMessage;

public:
		Exceptions(const string& errorString);
		~Exceptions();
		string getMessage() const;
};