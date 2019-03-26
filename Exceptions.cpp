#include<iostream>
#include<string>
#include"Exceptions.h"

using namespace std;

Exceptions::Exceptions(const string& errorString)
{
	errorMessage = errorString;
	cout << "\nERROR: " << getMessage() << "\nProgram Aborting...\nCalling Terminate Method...\n";
}

Exceptions::~Exceptions()
{}

string Exceptions::getMessage() const
{
	return errorMessage;
}