#include "Array.h"
#include <iostream>
using namespace std;

template<typename T>
Array<T>::Array(int cap)
{
	cout << "\nArray";
	if (cap <= 0)
	{
		capacity = 0;
		data = nullptr;
		return;
	}
	capacity = cap;
	data = new T[capacity];
}
template<typename T>
T& Array<T>:: operator[](int i)
{
	if (isValidIndex(i))
		return data[i];
	exit(0);
}

template<typename T>
const T& Array<T>:: operator[](int i)const
{
	if (isValidIndex(i))
		return data[i];
	exit(0);
}
template<typename T>
int Array<T>::getCapacity()const
{
	return capacity;
}
template<typename T>
Array<T>::~Array()
{
	if (data)
		delete[]data;
	data = nullptr;
	capacity = 0;
}
template <typename T>
void Array<T>::reSize(int newCapacity)
{
	if (newCapacity <= 0)
	{
		this->~Array();
		return;
	}
	if (newCapacity == capacity)
		return;
	T* temp = new T[newCapacity];
	for (int i = 0; i < newCapacity && i < capacity; i++)
		temp[i] = data[i];
	this->~Array();
	capacity = newCapacity;
	data = temp;
	temp = nullptr;
}
template<typename T>
Array<T>& Array<T> :: operator=(const Array<T>& ref)
{
	if (this == &ref)
		return *this;
	this->~Array();
	if (!ref.data)
		return *this;
	capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = ref.data[i];
	return *this;
}
template<typename T>
Array<T>& Array<T> :: operator=(Array<T>&& ref)
{
	this->~Array();
	data = ref.data;
	capacity = ref.capacity;
	ref.data = nullptr;
	ref.capacity = 0;
	return *this;
}
template<typename T>
bool Array<T> ::isValidIndex(int index)const
{
	return index >= 0 && index < capacity;
}
template<typename T>
Array<T>::Array(const Array<T>& ref)
{
	if (!ref.data)
	{
		data = nullptr;
		capacity = 0;
		return;
	}
	capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = ref.data[i];
}
template <typename T>
Array<T>::Array(Array<T>&& ref)
{
	data = ref.data;
	capacity = ref.capacity;
	ref.data = nullptr;
	ref.capacity = 0;
}
