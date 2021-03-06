/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	Project 2: Virtual Machine
*/
#ifndef VECTOR_HPP
#define VECTOR_HPP

/*#include <vector>
template<typename T>
using Vector = std::vector<T>;*/
#include <stdio.h>

template <class T> class allocator{
public:
	T* allocate(size_t);
	void deallocate(T*, size_t);
	void construct(T*, const T&);
	void destroy(T*);
};

template <class Out, class T>
void unitialized_fill(Out, Out, const T&);

template <class In, class Out>
Out uninitialized_copy(In, In, Out);

template <class T> class Vec{
	public:
		using iterator = T*;
		using const_iterator = const T*;
		using size_type = size_t;
		using value_type = T;

		Vec(){
			this->create();
		}

		explicit Vec(size_type n, const T& val = T()){
			create(n, val);
		}

		Vec(const Vec& v){
			create(v.begin(), v.end());
		}

		Vec& operator=(const Vec&);
		~Vec(){
			this->uncreate();
		}

		T& operator[](size_type i){
			return data[i];
		}

		const T& operator[](size_type i) const{
			return data[i];
		}

		void push_back(const T& t){
			if(avail == limit){
				this->grow();
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
		void create();
		void create(Vec<T>::size_type, const T&);
		void create(Vec<T>::const_iterator, Vec<T>::const_iterator);
		void uncreate();
		void grow();
		void unchecked_append(const T&);

	private:
		iterator data;
		iterator avail;
		iterator limit;
		allocator<T> alloc(size_type);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec &rhs){
	if(&rhs != this){
		this->uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

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

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j){
	data = alloc.allocate(j - i);
	limit = avail = uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::uncreate(){
	if(data){
		iterator it = avail;
		while(it != data){
			alloc.destroy(--it);
		}
		alloc.deallocate(data, limit - data);
	}
	data = limit = avail = 0;
}

template <class T>
void Vec<T>::grow(){
	size_type new_size = max(2 * (limit - data), this->ptrdiff_t(1));
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = uninitialized_copy(data, avail, new_data);
	uncreate();
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val){
	alloc.construct(avail++, val);
}


#endif
