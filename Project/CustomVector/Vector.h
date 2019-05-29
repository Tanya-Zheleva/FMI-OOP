#pragma once

template <class T>
class Vector
{
private:
	T* m_buffer;
	int index;
	int m_size;
	int m_capacity;

	void free();
	void calcCapacity(int);
	int getNextPowerOfTwo(int) const;
	void fill(const T&);
	void copyFrom(const Vector<T>&);

public:
	//TODO: Add move constructor

	Vector();
	Vector(const unsigned int); // n elements, if int all are 0
	Vector(unsigned int, const T&); // n elements with value m
//	Vector(typename vector<T>::iterator, typename vector<T>::iterator); // range constructor
//	Vector(std::initializer_list<T>); // move constructor ?
	Vector(const Vector<T>&);
	~Vector();
	Vector<T>& operator=(const Vector<T>&);

	T& operator [](const int);
	const T& operator [](const int) const;

	//void push_back(const T&);
	//void pop_back();

	unsigned int size() const;
	unsigned int capacity() const;
	void resize(unsigned int);
	bool empty() const;
	//const T& back() const; // value of last element
	//void clear();


	void print() const;
};

template <class T>
Vector<T>::Vector()
{
	m_size = 0;
	index = 0;
	m_capacity = 2;
	m_buffer = new T[m_capacity];
}

template <class T>
Vector<T>::Vector(const unsigned int size)
{
	calcCapacity(size);

	index = 0;
	m_size = size;
	m_buffer = new T[size];
}

template <class T>
Vector<T>::Vector(unsigned int size, const T& value)
{
	calcCapacity(size);

	m_size = size;
	index = size;
	m_buffer = new T[size];
	fill(value);
}

template <class T>
Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <class T>
Vector<T>::~Vector()
{
	free();
}

template <class T>
T& Vector<T>::operator[](const int index)
{
	if (index < 0 || index >= m_size)
	{
		throw std::out_of_range("Index out of range.");
	}

	return m_buffer[index];
}

template <class T>
const T& Vector<T>::operator[](const int index) const
{
	if (index < 0 || index >= m_size)
	{
		throw std::out_of_range("Index out of range.");
	}

	return m_buffer[index];
}

template <class T>
unsigned int Vector<T>::size() const
{
	return m_size;
}

template <class T>
unsigned int Vector<T>::capacity() const
{
	return m_capacity;
}

template <class T>
bool Vector<T>::empty() const
{
	return index == 0;
}

template <class T>
void Vector<T>::resize(unsigned int n)
{
	if (n < m_size)
	{
		T* temp = new T[n];

		for (int i = 0; i < n; i++)
		{
			temp[i] = m_buffer[i];
		}

		free();
		m_buffer = new T[n];

		for (int i = 0; i < n; i++)
		{
			m_buffer[i] = temp[i];
		}

		delete[] temp;
		m_size = n;
	}
}


//private
template <class T>
void Vector<T>::fill(const T& value)
{
	for (int i = 0; i < m_size; i++)
	{
		m_buffer[i] = value;
	}
}

template <class T>
void Vector<T>::calcCapacity(int size)
{
	int power = getNextPowerOfTwo(size);
	m_capacity = power;
}

template <class T>
int Vector<T>::getNextPowerOfTwo(int n) const
{
	int power = 1;

	while (power < n)
	{
		power *= 2;
	}

	return power;
}

template <class T>
void Vector<T>::free()
{
	delete[] m_buffer;
}

template <class T>
void Vector<T>::copyFrom(const Vector<T>& other)
{
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	index = other.index;

	m_buffer = new T[m_size];

	for (int i = 0; i < index; i++)
	{
		m_buffer[i] = other.m_buffer[i];
	}
}


















template <class T>
void Vector<T>::print() const
{
	for (int i = 0; i < index; i++)
	{
		std::cout << m_buffer[i] << ' ';
	}

	std::cout << std::endl;
}