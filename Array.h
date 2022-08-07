#ifndef ARRAY_H
#define ARRAY_H
#include<cstdlib>
template<typename T>
class Array
{
	T* data;
	int capacity;

	bool isValidIndex(int index)const;
public:
	~Array();
	T& operator[](int i);
	const T& operator[](int i)const;
	int getCapacity()const;
	void reSize(int newCapacity);
	Array<T>& operator=(const Array<T>&);
	Array(const Array<T>&);
	Array<T>& operator=(Array<T>&&);
	Array(Array<T>&&);
	Array(int = 0);
};
#endif // !ARRAY_H
