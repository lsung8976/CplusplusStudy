/*
	파일이름 : AccountArray.h
	작성자 : 이성준
	업데이트 정보 : [2020.11.21], 파일버젼 : 0.8
*/

#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__
#include "Account.h"

typedef Account* ACCOUNT_PTR;

class AccountArray
{
private:
	ACCOUNT_PTR* pArr;
	int arrLen;

	AccountArray(const AccountArray& arr) {}
	AccountArray& operator=(const AccountArray& arr) {}
public:
	AccountArray(int Len = 100);
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR& operator[] (int idx) const;
	int GetArrLen() const;
	~AccountArray();
};

#endif __ACCOUNT_ARRAY_H__