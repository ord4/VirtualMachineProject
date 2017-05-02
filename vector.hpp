/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	Project 2: Virtual Machine
*/
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "test.hpp"

/*#include <vector>
template<typename T>
using Vector = std::vector<T>;*/

template <class T> class Vec{
	public:
		using iterator = T*;
		using const_iterator = const T*;
		using size_type = size_t;
		using value_type = T;

		Vec(){
			create();
		}

		explicit Vec(size_type n, const T& val = T()){
			create(n, val);
		}

		Vec(const Vec& v){
			create(v.begin(), v.end());
		}

		Vec& operator=(const Vec&);
		~Vec(){
			uncreate();
		}

		T& operator[](size_type i){
			return data[i];
		}

		const T& operator[](size_type i) const{
			return data[i];
		}

		void push_back(const T& t){
			if(avail == limit){
				grow();
			}
			unchecked_append(t);
		}

		size_type size() const{
			return avail - data;
		}

		iterator begin(){
			return data;
		}
		const_iterator begin() const{
			return data;
		}

		iterator end(){
			return avail;
		}
		const_iterator end() const{
			return avail;
		}

	private:
		iterator data;
		iterator avail;
		iterator limit;
};

template <class T>
void Vec<T>::create(){
	data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val){
	data = alloc.allocate(n);
	limit = avail = data + n;
	uninitialized_fill(data, limit, val);
}

#endif
