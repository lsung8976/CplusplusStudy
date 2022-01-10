/*
	�����̸� : AccountHandler.h
	�ۼ��� : �̼���
	������Ʈ ���� : [2020.11.02], ���Ϲ��� : 0.7
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