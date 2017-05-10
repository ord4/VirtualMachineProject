/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	Project 2: Virtual Machine
*/
#ifndef STRING_HPP
#define STRING_HPP

#include <string.h>
#include <iostream>

class String{
	private:
		int length;
		char *str;

	public:
		String();
		~String();
		String(const String&);

		String& operator=(const String&);
		String operator+=(const String&);

		int getLength() const;
		void setLength(int);
};

String::String(){
	setLength(1);
	str = new char[getLength()];
	str[0] = '\0';
}

String::String(const String &obj){
	setLength(obj.getLength());
	str = new char[getLength() + 1];
	strcpy(str, obj.str);
}

String& String::operator=(const String &rhs){
	setLength(rhs.getLength());
	char *tempStr = new char[getLength() + 1];
	strcat(tempStr, rhs.str);
	return *this;
}

String::~String(){
	if(str){
		delete []str;
	}
}

String String::operator+=(const String& rhs){
	setLength(rhs.getLength());
	char *tempStr = str;
	str = new char[getLength() + 1];
	strcpy(str, tempStr);
	strcat(str, rhs.str);
	delete tempStr;
	return *this;
}

int String::getLength() const{
	return length;
}

void String::setLength(int val){
	length = val;
}
#endif
