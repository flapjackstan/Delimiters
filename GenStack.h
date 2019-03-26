#pragma once
#include<iostream>
#include <string>
#include "StackExceptions.h"


using namespace std; 
template <class generic_data_type>

	class GenStack
	{
	//Member Variables
	private:
		int size;
		int top;
		int elements;
		generic_data_type* myArray;

	//Constructors and Destructors
	public:
		GenStack()
		{
			myArray = new generic_data_type(128);
			size = 128;
			top = -1;
			elements = 0;
		};

		GenStack(int maxSize)
		{
			myArray = new generic_data_type(maxSize);
			size = maxSize;
			top = -1;
			elements = 0;
		};

		~GenStack()
		{
			myArray = NULL;
			delete myArray;
		};

	//Member Methods
	public:
		void push(generic_data_type d)
		{	
			myArray[top++] = d;
			elements++;
		};

		generic_data_type pop() throw (StackEmpty)
		{
			if(isEmpty()) throw StackEmpty("Stack is Empty");
			elements--;
			return myArray[top--];
		};

		generic_data_type peek()
		{
			return myArray[top-1];
		};

		bool isFull()
		{
			return (top >= size -1);
		};

		bool isEmpty()
		{
			return (top <= -1);
		};

		int getSize()
		{
			return size;
		};

		int getNumberOfElements()
		{
			return elements;
		}
	};


