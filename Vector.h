#ifndef VECTOR
#define VECTOR
#include <iostream>

template <typename T>
class Vector {

public:
        Vector(const int size = 5);
        Vector(const Vector & rhs);
        ~Vector();

        void operator=(const Vector & rhs);
        void push_back(T value);
        void insert_at(int index, T value);
        int get_at(int index);
        int size();
        void print();

private:
        T * m_vector;
        int m_size;
        int m_current;
        void resizeVector();
        void copyFrom(const Vector & rhs);
};

template <typename T>
Vector<T>::Vector(const int size) {
	if(size < 1) {
		std::cout << "Size is less than 1";
		return;
	}
	m_size = size;
	m_vector = new T[m_size];
	m_current = 0;
}

template <typename T>
Vector<T>::Vector(const Vector & rhs) {
	copyFrom(rhs);
}

template <typename T>
Vector<T>::~Vector() {
	delete [] m_vector;	
}

template <typename T>
void Vector<T>::operator=(const Vector & rhs) {
	if(this == &rhs) {
		std::cout << "Self assignment";
		return *this;
	}
	delete [] m_vector;
	copyFrom(rhs);
	return *this;
}

template <typename T>
void Vector<T>::copyFrom(const Vector & rhs) {
	m_size = rhs.m_size;
	m_current = rhs.m_current;
	m_vector = new int[m_size];
	for(int ix = 0; ix < m_size; ++ix) {
		m_vector[ix] = rhs.m_vector[ix];
	}
}

template <typename T>
void Vector<T>::insert_at(int index, T value) {
	if(index >= m_size || index < 0) {
		std::cout << "Out of Range";
		return;
	}
	m_vector[index] = value;
}

template <typename T>
void Vector<T>::push_back(T value) {
	if(m_current == m_size) 
		resizeVector();
	
	m_vector[m_current++] = value;
}

template <typename T>
void Vector<T>::resizeVector() {
	T * tmpVector = new T[m_size * 2];
	for(int ix = 0; ix < m_size; ++ix) 
		tmpVector[ix] = m_vector[ix];
	
	delete [] m_vector;
	m_vector = tmpVector;
	m_size *= 2;
	tmpVector = nullptr;	
}

template <typename T>
int Vector<T>::size() {
	return m_current;
}

template <typename T>
void Vector<T>::print() {
	for(int ix = 0; ix < m_current; ++ix)
		std::cout << m_vector[ix] << std::endl;
}
#endif
