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
	int calculateClosestPowerOfTwo() const;

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
	T& at(const unsigned int) const;

	void push_back(const T&);
	void pop_back();

	int size() const;
	int capacity() const; // *bonus*
	void resize(const int);
	bool empty() const;
	const T& back() const; // value of last element
	const T& front() const; //value of first element *bonus*
	void clear();
	void swap(Vector<T>&); // *bonus*

	void print() const;

	class Iterator
	{
	private:
		Node<T>* start;
		Node<T>* current;

	public:
		Iterator() : start(first), current(first)
		{
		}

		Iterator(Node<T>* ptr) : start(ptr), current(ptr)
		{
		}

		Iterator& operator=(Node<T>* ptr)
		{
			current = ptr;

			return *this;
		}

		Iterator& operator +=(int positions)
		{
			while (positions > 0 && current == nullptr)
			{
				current = current->next;
				positions--;
			}

			return *this;
		}

		bool operator!=(const Iterator& iterator) const
		{
			return current != iterator.current;
		}

		bool operator==(const Iterator& iterator) const
		{
			return current == iterator.current;
		}

		T& operator*() const
		{
			return current->value;
		}

		Iterator& operator++()
		{
			if (current)
			{
				current = current->next;
			}

			return *this;
		}

		Iterator& operator++(int)
		{
			Iterator iterator = *this;
			++*this;

			return iterator;
		}
	};

	Iterator begin() const
	{
		return Iterator(first);
	}

	Iterator end() const
	{
		return Iterator(nullptr);
	}
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
int Vector<T>::size() const
{
	return index;
}

template <typename T>
int Vector<T>::capacity() const
{
	return calculateClosestPowerOfTwo();
}

template <typename T>
const T& Vector<T>::back() const
{
	return last->value;
}

template <typename T>
const T& Vector<T>::front() const
{
	return first->value;
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
void Vector<T>::swap(Vector<T>& other)
{
	Vector<T> temp = *this;
	*this = other;
	other = temp;
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
	return at(positon);
}

template <typename T>
const T& Vector<T>::operator[](const unsigned int position) const
{
	return at(position);
}

template <typename T>
T& Vector<T>::at(const unsigned int positon) const
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

//private

template <typename T>
int Vector<T>::calculateClosestPowerOfTwo() const
{
	if (index < 2)
	{
		return 2;
	}

	int capacity = 2;

	while (capacity <= index)
	{
		capacity *= 2;
	}

	return capacity;
}

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