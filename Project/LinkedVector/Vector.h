#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class Vector
{
private:
	Node<T>* first;
	Node<T>* last;
	unsigned int index;

	void free();
	void fill(const unsigned int, const T&);
	void copyFrom(const Vector<T>&);
	T& elementAt(const unsigned int) const;

public:
	//TODO: Add move constructor

	Vector();
	Vector(const unsigned int); // n elements, if int all are 0
	Vector(const unsigned int, const T&); // n elements with value m
//	Vector(typename vector<T>::iterator, typename vector<T>::iterator); // range constructor
//	Vector(std::initializer_list<T>); // move constructor ?
	Vector(const Vector<T>&);
	~Vector();
	Vector<T>& operator=(const Vector<T>&);

	T& operator [](const unsigned int);
	const T& operator [](const unsigned int) const;

	void push_back(const T&);
	void pop_back();

	unsigned int size() const;
	void resize(const int);
	bool empty() const;
	const T& back() const; // value of last element
	void clear();


	void print() const;
};

template <typename T>
Vector<T>::Vector()
{
	index = 0;
	first = nullptr;
	last = nullptr;
}

template <typename T>
Vector<T>::Vector(const unsigned int n)
{
	fill(n, T());
}

template <typename T>
Vector<T>::Vector(const unsigned int n, const T& value)
{
	fill(n, value);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template <typename T>
Vector<T>::~Vector()
{
	clear();
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		clear();
		copyFrom(other);
	}

	return *this;
}

// operations

template <typename T>
unsigned int Vector<T>::size() const
{
	return index;
}

template <typename T>
const T& Vector<T>::back() const
{
	return last->value;
}

template <typename T>
bool Vector<T>::empty() const
{
	return first == nullptr;
}

template <typename T>
void Vector<T>::clear()
{
	Node<T>* temp = first;

	while (temp != nullptr)
	{
		temp = temp->next;
		delete first;
		first = temp;
	}

	index = 0;
}

template <typename T>
void Vector<T>::push_back(const T& value)
{
	Node<T>* temp = new Node<T>(value);
	temp->next = nullptr;

	if (!first)
	{
		first = temp;
		last = first;
	}
	else
	{
		last->next = temp;
		last = temp;
	}

	index++;
	temp = nullptr; //must? no delete
}

template <typename T>
void Vector<T>::pop_back()
{
	Node<T>* current = first;
	Node<T>* prev = nullptr;

	while (current->next != nullptr)
	{
		prev = current;
		current = current->next;
	}

	last = prev;
	prev->next = nullptr;

	index--;
	delete current;
}

template <typename T>
void Vector<T>::resize(const int n)
{
	if (n < 0)
	{
		throw std::invalid_argument("New size cannot be negative.");
	}

	if (index == n)
	{
		return;
	}

	if (n < index)
	{
		while (index >= n)
		{
			pop_back();
			index--;
		}

		return;
	}

	while (index <= n)
	{
		push_back(T());
		index++;
	}
}

// access
template <typename T>
T& Vector<T>::operator[](const unsigned int positon)
{
	return elementAt(positon);
}

template <typename T>
const T& Vector<T>::operator[](const unsigned int position) const
{
	return elementAt(position);
}


//private

template <typename T>
void Vector<T>::fill(const unsigned int times, const T& value)
{
	for (unsigned i = 0; i < times; i++)
	{
		push_back(value);
	}
}

template <typename T>
void Vector<T>::copyFrom(const Vector<T>& other)
{
	Node<T>* temp = other.first;

	while (temp != nullptr)
	{
		push_back(temp->value);
		temp = temp->next;
	}
}

template <typename T>
T& Vector<T>::elementAt(const unsigned int positon) const
{
	if (positon >= index)
	{
		throw std::out_of_range("Index out of range.");
	}

	int current = 0;

	Node<T>* temp = first;

	while (temp != nullptr)
	{
		if (positon == current)
		{
			return temp->value;
		}

		temp = temp->next;
		current++;
	}
}

////////////////////////////

template <typename T>
void Vector<T>::print() const
{
	Node<T>* temp = first;

	while (temp != nullptr)
	{
		std::cout << temp->value << ' ';
		temp = temp->next;
	}

	std::cout << std::endl;
}