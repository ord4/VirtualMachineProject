/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	Project 2: Virtual Machine
*/
#ifndef STACK_HPP
#define STACK_HPP

#include <stack>
/*// You *must* implement a stack.
template<typename T>
using Stack = std::stack<T>;*/

template <class T> struct Node{
	T data;
	T *nextPtr;
};

template <class T> class Stack{
	private:
		std::size_t stackSize;
		Node<T> *top;
	public:
		Stack();
		Stack(const Stack &obj);
		void push_front(T value);
		void pop();
		bool isEmpty();
		std::size_t size() const;
		//template<typename T> top();
		//template<class T>* top();
};

template <class T>
Stack<T>::Stack(){
	stackSize = 0;
	top = nullptr;
}

template <class T>
Stack<T>::Stack(const Stack &obj){
	if(obj.top == nullptr){
		top = nullptr;
	}
	else{
		Node *ptr = obj.top;
		while(ptr != nullptr){
			push_front(ptr->data);
			ptr = ptr->nextPtr;
		}
	}
}

template <class T>
void Stack<T>::push_front(T value){
	stacksize++;

	Node<T> *newNode = new Node<T>;

	newNode->data = value;
	newNode->nextPtr = top;

	top = newNode;
}

template <class T>
void Stack<T>::pop(){
	if(isEmpty()){
		return;
	}
	else{
		Node<T> *temp = top;

		top = top->nextPtr;

		delete(temp);

		stackSize--;
	}
}

template <class T>
bool Stack<T>::isEmpty(){
	if(top == nullptr){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
std::size_t Stack<T>::size() const{
	return stackSize;
}

#endif
