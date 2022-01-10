/*
	�����̸� : NormalAccount.h
	�ۼ��� : �̼���
	������Ʈ ���� : [2020.11.02], ���Ϲ��� : 0.7
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

class NormalAccount : public Account
{
private:
	int interest;
public:
	NormalAccount(int id, String name, int money, int rate)
		:Account(id, name, money), interest(rate) {}
	virtual void PlusMyMoney(int plus)
	{
		double add_money = plus + plus * interest / 100;
		Account::PlusMyMoney(int(add_money));
	}
};

#endif