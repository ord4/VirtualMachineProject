/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	Project 2: Virtual Machine
*/
#ifndef STACK_HPP
#define STACK_HPP

template<class T>
struct Node{
	T data;
	Node *nextPtr;
};

template <class T>
class Stack{
	private:
		std::size_t stackSize;
		Node *top;

	public:
		// Constructors
		Stack();
		Stack Stack(const Stack&);

		// Functions
		bool empty();
		std::size_t size();
		T top();
		T& top();
		void push_front(T);
		void pop();
};

// Assignment operator
Stack& operator=(const Stack &rhs){
	if(this == &rhs){
		return *this;
	}
	else{
		// Copy over elements somehow

		}

		return *this;
	}
}

template <class T>
Stack<T>::Stack(){
	top = nullptr;
}

template <class T>
Stack Stack<T>::Stack(const Stack &obj){
	
}

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
T Stack<T>::top(){
	return *top;
}

template <class T>
T& Stack<T>::top(){
	return top;
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
void Stack<T>::pop(){
	if(!empty()){
		Node<T> *tempNode = top;

		top = top->nextPtr;

		delete(tempNode);
		stackSize--;
	}
	else{
		return;
	}
}


#endif
