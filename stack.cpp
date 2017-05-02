/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	Project 2: Virtual Machine
#include "stack.hpp"

// Default constructor
Stack::Stack(){
	top = nullptr;
	stackSize = 0;
}

// Copy Constructor
Stack::Stack(const Stack &obj){
	if(obj.top == nullptr){
		top = nullptr;
	}
	else{
		Node *ptr = obj.top
		while(ptr != nullptr){
			push_front(ptr->data);
			ptr = ptr->nextPtr;
		}
	}
}
*/
