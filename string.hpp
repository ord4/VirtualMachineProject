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

class String{
	private:
		int length;
		char *str;

	public:
		// Constructors
		String();
		String(const char*);
		String(const std::string&);
		String(const char*, int);
		String(const String&, const String&);
		String(const String&);

		// Destructor
		~String();

		// Overloaded Operators
		char& operator[](int) const;
		friend bool operator==(const String&, const String&);
		friend bool operator!=(const String&, const String&);
		friend bool operator>(const String&, const String&);
		friend bool operator<(const String&, const String&);
		friend String operator+(const String&, const String&);
		friend std::ostream& operator<<(std::ostream&, String&);

		// Setters and Getters
		int getLength()const {return length;}
		void setLength(int x){length = x;}
		char* getStr() const{return str;}


};
#endif
