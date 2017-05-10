/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	Project 2: Virtual Machine
*/
#include "string.hpp"

#include <iostream>
#include <cstring>
#include <string>

String::String(){
	length = 0;
	str = nullptr;
}

String::String(const char *arrPtr){
	length = strlen(arrPtr);
	str = new char[length + 1];
	strcpy(str, arrPtr);
}

String::String(const std::string &s){
	length = s.length();
	if(length == 0){
		str = nullptr;
	}
	else{
		str = new char[length];
		for(int i = 0; i < length - 1; ++i){
			str[i] = s[i];
		}
		str[length] = '\0';
	}
}

String::String(const char *s, int size){
	length = strlen(s);
	str = new char[length + 1];
	strcpy(str, s);
}

String::String(const String &s1, const String &s2){
	length = s2.length + s1.length;
	str = new char[length + 1];
	strcpy(str, s1.str);
	strcpy(str + s1.length, s2.str);
}

String::String(const String &s){
	length = s.length;
	str = new char[length + 1];
	strcpy(str, s.str);
}

String::~String(){
	str = nullptr;
	delete []str;
}

char& String::operator[](int i) const{
	return str[i];
}

bool operator==(const String &lhs, const String &rhs){
	if(lhs.length == rhs.length){
		for(int i = 0; i < rhs.length; ++i){
			if(lhs[i] != rhs[i]){
				return false;
			}
		}
		return true;
	}
	else{
		return false;
	}
}

bool operator!=(const String &lhs, const String &rhs){
	return !(lhs == rhs);
}

bool operator>(const String &rhs, const String &lhs){
	return(rhs.length > lhs.length);
}

bool operator<(const String &rhs, const String &lhs){
	return(rhs.length < lhs.length);
}

String operator+(const String &rhs, const String &lhs){
	return String(lhs, rhs);
}

std::ostream& operator<<(std::ostream& os, String &s){
	return os << s.getStr();
}
