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
		int stackSize;
		Node<T> *top;
	public:
		Stack(){
			top = nullptr;
			stackSize = 0;
		}

		Stack(const Stack &obj){
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

		void push_front(T value){
			// Increase the stack size by 1
			stackSize++;

			// Create a new node
			Node<T> *newNode = new Node<T>;

			// Assign data to the value and pushed to the top of stack
			newNode->data = value;
			newNode->nextPtr = top;

			// Change the top of the stack pointer
			top = newNode;
		}

		void pop(){
			if(isEmpty()){
				return;
			}
			else{
				Node<T> *temp = top;
				top = top->nextPtr;
				delete(temp);
			}
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

		template<typename T> top(){
			return top->data;
		}

		template<class T>* top(){
			return top;
		}

};



#endif
