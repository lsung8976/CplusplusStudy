/*
	�����̸� : HighCreditAccount.h
	�ۼ��� : �̼���
	������Ʈ ���� : [2020.11.26], ���Ϲ��� : 0.8
*/

#ifndef __HIGHCRDITACCOUNT_H__
#define __HIGHCRDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int creditLevel;
public:
	HighCreditAccount(int id, String name, int money, int rate, int level)
		:NormalAccount(id, name, money, rate), creditLevel(level) {}
	virtual void PlusMyMoney(int plus)
	{
		NormalAccount::PlusMyMoney(plus);
		Account::PlusMyMoney(plus * creditLevel / 100);
	}
};

#endif