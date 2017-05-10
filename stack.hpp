/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	Project 2: Virtual Machine
*/
#ifndef STACK_HPP
#define STACK_HPP

#include <stdio.h>
#include <stdlib.h>

template<class T>
struct Node{
	T data;
	Node<T> *nextPtr;
};

template <class T>
class Stack{
	private:
		std::size_t stackSize;
		Node<T> *top;

	public:
		// Constructors
		Stack();
		Stack(const Stack&);

		// Functions
		bool empty();
		std::size_t size();
		T returnTop();
		void push_front(T);
		void pop(T&);
};

//template <class T>
//Stack<T>& operator=(const Stack<T> &rhs){}

template <class T>
Stack<T>::Stack(){
	top = nullptr;
}

template <class T>
Stack<T>::Stack(const Stack<T> &obj){}

template <class T>
bool Stack<T>::empty(){
	if(top == nullptr){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
std::size_t Stack<T>::size(){
	return stackSize;
}

template <class T>
T Stack<T>::returnTop(){
	return *top;
}

template <class T>
void Stack<T>::push_front(T val){
	stackSize++;

	Node<T> *newNode = new Node<T>;

	newNode->data = val;
	newNode->nextPtr = top;

	top = newNode;
}

template <class T>
void Stack<T>::pop(T &num){
	if(!empty()){
		Node<T> *tempNode = top;
		num = *top;

		top = top->nextPtr;

		delete(tempNode);
		stackSize--;
	}
	else{
		return;
	}
}


#endif
