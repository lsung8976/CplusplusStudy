/*
	파일이름 : AccountHandler.h
	작성자 : 이성준
	업데이트 정보 : [2020.11.02], 파일버젼 : 0.7
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler
{
private:
	BoundCheckArray<Account*> pAcc;
	int count;
public:
	AccountHandler();
	void InitPrt(void);
	void MakeAccount(void);
	void AccPrt(void);
	void ReciptMyMoney(void);
	void PayMyMoney(void);
	~AccountHandler();

};
#endif __ACCOUNT_HANDLER_H__