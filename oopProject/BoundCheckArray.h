#ifndef __BOUND_CHECK_ARRAY_H__
#define __BOUND_CHECK_ARRAY_H__

#include "BankingCommonDecl.h"

//typedef Account* ACCOUNT_PTR;

template <typename T>
class BoundCheckArray
{
private:
	T* pArr;
	int arrLen;

	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}
public:
	BoundCheckArray(int Len = 100);
	T& operator[] (int idx);
	T& operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int Len) : arrLen(Len)
{
	pArr = new T[arrLen];
}

template <typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
	if (idx<0 || idx>arrLen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return pArr[idx];
}

template <typename T>
T& BoundCheckArray<T>::operator[] (int idx) const
{
	if (idx<0 || idx>arrLen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return pArr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const { return arrLen; }

template <typename T>
BoundCheckArray<T>::~BoundCheckArray() { delete[] pArr; }

#endif