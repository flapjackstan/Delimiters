#include <iostream>
#include <string>
#include "Exceptions.h"

using namespace std;

class StackFull : public Exceptions
{
public: 
	StackFull(const string& errorString) : Exceptions(errorString){}
};

class StackEmpty : public Exceptions
{
public: 
	StackEmpty(const string& errorString) : Exceptions(errorString){}
};