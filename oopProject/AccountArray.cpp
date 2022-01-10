/*
	�����̸� : AccountArray.h
	�ۼ��� : �̼���
	������Ʈ ���� : [2020.11.21], ���Ϲ��� : 0.8
*/

#include "BankingCommonDecl.h"
#include "AccountArray.h"


AccountArray::AccountArray(int Len) : arrLen(Len)
{
	pArr = new ACCOUNT_PTR[arrLen];
}

ACCOUNT_PTR& AccountArray::operator[] (int idx)
{
	if (idx<0 || idx>arrLen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return pArr[idx];
}

ACCOUNT_PTR& AccountArray::operator[] (int idx) const
{
	if (idx<0 || idx>arrLen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return pArr[idx];
}

int AccountArray::GetArrLen() const { return arrLen; }
AccountArray::~AccountArray() { delete[] pArr; }