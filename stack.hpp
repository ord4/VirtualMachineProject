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

template <class T> class Stack{
	private:
		struct Node{
			T data;
			T *nextPtr;
		};
		struct Node *top;
		int stackSize;

	public:
		Stack(){
			top = nullptr;
			stackSize = 0;
		}

		bool isEmpty(){
			if(top == nullptr){
				return true;
			}
			else{
				return false;
			}
		}

		std::size_t size() const{
			return stackSize;
		}

		template<class T> top(){
			return top->data;
		}

		template<class T>* top(){
			return top;
		}

		void push_front(T value){
			stackSize++;

			struct Node *newNode;
			newNode = new Node;

			newNode->data = value;
			newNode->nextPtr = nullptr;

			if()
		}
}

#endif
