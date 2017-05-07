/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	Project 2: Virtual Machine
*/
#ifndef STRING_HPP
#define STRING_HPP

#include <string>
#include <iostream>

// Helper functions
int stringLength(char*);
void stringCopy(char*, char*, int);

int stringLength(char *ptr){
	int length = 0;
	char *p = ptr;
	while(*p != '\0'){
		length++;
		p++;
	}
	return length;
}

void stringCopy(char *dest, char *src, int size){
	for(int i = 0; i < size; ++i){
		dest[i] = src[i];
	}
}

class myString{
	private:
		int length;
		char *myStr;

	public:
		// Constructors
		myString();
		myString(char*);
		myString(const myString&);
		~myString();

		// Functions
		int size();
};

// Overloaded operators
std::ostream& operator<<(std::ostream&, const myString&);

myString& operator=(const myString&);

char& operator[](int);

myString operator+(const myString&, const myString&);
myString operator+(const myString&, char);
myString operator+(char, const myString&);

bool operator==(const myString&, const myString&);
bool operator==(const myString&, const char&);
bool operator==(const char&, const myString&);

bool operator!=(const myString&, const myString&);
bool operator!=(const myString&, const char&);
bool operator!=(const char&, const myString&);

bool operator<(const myString&, const myString&);
bool operator<(const myString&, const char&);
bool operator<(const char&, const myString&);

bool operator>(const myString&, const myString&);
bool operator>(const myString&, const char&);
bool operator>(const char&, const myString&);



myString::myString(){
	length = 0;
	myStr = nullptr;
}

myString::myString(char *val){
	length = stringLength(val);
	myStr = new char[length];
	stringCopy(myStr, val, length);
}

myString::myString(const myString& obj){
	length = obj.length;
	myStr = new char[length];
	stringCopy(myStr, obj.myStr, length);
}

myString::~myString(){
	delete [] myStr;
}

int myString::size(){
	return length;
}

std::ostream& operator<<(std::ostream &os, const myString &obj){
	for(int i = 0; i < obj.length; ++i){
		os.put(obj.myStr[i]);
	}
	return os;
}

myString& operator=(const myString& obj){
	if(this != &obj){
		delete [] myStr;
		length = obj.length;
		myStr = new char[length];
		stringCopy(myStr, obj.myStr, length);
	}
	return *this;
}

char& operator[](int index){
	if(index < 0 || index > length){
		std::cout << "Trying to access item out of bounds.\n";
		exit(-1);
	}
	return myStr[index];
}

myString operator+(const myString &left, const myString &right){
	myString newString;
	newString.length = left.length + right.length;
	newString.myStr = new char[newString.length];
	stringCopy(newString.myStr, left.myStr, left.length);
	stringCopy(newString.myStr + left.length, right.myStr, right.length);
	return newString;
}
myString operator+(const myString &left, char right){
	myString newString;
	newString.length = left.length + 1; // Should this be 2 for '\0'?
	newString.myStr = new char[newString.length];
	stringCopy(newString.myStr, left.myStr, left.length);
	stringCopy(newString.myStr + left.length, right, 1);
	return newString;
}
myString operator+(char left, myString &right){
	myString newString;
	newString.length = 1 + right.length;
	newString.myStr = new char[newString.length];
	stringCopy(newString.myStr, left, 1);
	stringCopy(newString.myStr + 1, right.myStr, right.length);
}

bool operator==(const myString &left, const myString &right){
	if(left.length != right.length){
		return false;
	}
	else{
		int i = 0;
		for(int i = 0; i < left.length; ++i){
			if(left[i] != right[i]){
				return false;
			}
		}
		return true;
	}
}
bool operator==(const myString &left, const char &right){
	return left.myStr == right; // I don't think this is correct
}
bool operator==(const char &left, const myString &right){
	return left == right.myStr;
}



#endif
