/*
	파일이름 : Account.h
	작성자 : 이성준
	업데이트 정보 : [2020.11.26], 파일버젼 : 0.8
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "String.h"

class Account
{
private:
	int Accid;
	int myMoney;
	String Owner;
public:
	Account(int Accid, String Owner, int myMoney);
	Account(const Account& copy);
	Account& operator=(const Account& arr);
	~Account();
public:
	void ShowMyInfo() const;
	virtual void PlusMyMoney(int plus);
	void MinusMyMoney(int minus);
	int GetAccID() const;
	int GetMyMoney() const;
};

#endif __ACCOUNT_H__