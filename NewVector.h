#pragma once
#include <stdexcept>
template<typename T>
class NewVector
{
public:

	NewVector();
	NewVector(int size);
	NewVector(int size, T elem);
	NewVector(std::initializer_list<T> list);
	~NewVector();
	int size();
	int capacity();
	bool empty();
	void reserve(int capacity);
	void shrink_to_fit();
	void push_back(T);
	T& operator[](int index);
	T& at(int index);

private:

	T* vecPtr;
	int sz;
	int cap;
};

template <typename T>
NewVector<T>::NewVector()
{
	vecPtr = nullptr;
	sz = cap = 0;
}

template <typename T>
NewVector<T>::NewVector(int size)
{
	vecPtr = new T [size];
	cap = sz = size;
}

template <typename T>
NewVector<T>::NewVector(int size, T elem)
{
	vecPtr = new T [size];
	cap = sz = size;
	for (int i = 0; i < size; i++)
	{
		vecPtr[i] = elem;
	}
}

template <typename T>
NewVector<T>::NewVector(std::initializer_list<T> list)
{
	cap = sz = list.size();
	vecPtr = new T[sz];
	int i = 0;
	for(auto a = list.begin(); a != list.end(); a++)
	{
		vecPtr[i] = *a;
		i++;
	}
}

template <typename T>
NewVector<T>::~NewVector()
{
	cap = sz = 0;
	delete[] vecPtr;
}

template<typename T>
int NewVector<T>::size()
{
	return sz;
}

template<typename T>
int NewVector<T>::capacity()
{
	return cap;
}

template <typename T>
bool NewVector<T>::empty()
{
	return size == 0;
}

template <typename T>
void NewVector<T>::reserve(int capacity)
{
	if (capacity <= cap)
		return;
	if (sz == 0)
	{
		cap = capacity;
		vecPtr = new T[cap];
	}
	else
	{
		T* temp = new T [capacity];
		for (int i = 0; i < sz; i++)
		{
			temp[i] = vecPtr[i];
		}
		delete[] vecPtr;
		vecPtr = temp;
	}
}

template <typename T>
void NewVector<T>::shrink_to_fit()
{
	if (cap <= sz)
		return;
	cap = sz;
	T* temp = new T[sz];
	for (int i = 0; i < sz; i++)
	{
		temp[i] = vecPtr[i];
	}
	delete[] vecPtr;
	vecPtr = temp;
}

template<typename T>
void NewVector<T>::push_back(T value)
{
	if (cap == sz)
	{
		cap *= 2;
		T* temp = new T[cap];
		for (int i = 0; i < sz; i++)
		{
			temp[i] = vecPtr[i];
		}
		delete[] vecPtr;

		vecPtr = temp;
	}
	vecPtr[sz] = value;
	sz++;
}

template<typename T>
T& NewVector<T>::operator[](int index)
{
	return vecPtr[index];
}

template<typename T>
T& NewVector<T>::at(int index)
{
	if (index >= sz)
		throw(std::out_of_range);
	else
		return vecPtr[index];
}

