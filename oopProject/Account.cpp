/*
	�����̸� : Account.cpp
	�ۼ��� : �̼���
	������Ʈ ���� : [2020.11.26], ���Ϲ��� : 0.8
*/

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int Accid, String Owner, int myMoney)
	:Accid(Accid), Owner(Owner), myMoney(myMoney)	{}

Account::Account(const Account& copy) // ���� ������ �߰�
	: Accid(copy.Accid), Owner(copy.Owner), myMoney(copy.myMoney)	{}
Account& Account::operator=(const Account& arr)
{
	Accid = arr.Accid;
	myMoney = arr.myMoney;
	Owner = arr.Owner;

	return *this;
}

Account::~Account()
{}

void Account::ShowMyInfo() const
{
	cout << "���� : " << Owner << endl;
	cout << "���¹�ȣ : " << Accid << endl;
	cout << "���� �ܾ� :" << myMoney << endl;
}

void Account::PlusMyMoney(int plus)
{
	myMoney += plus;
}

void Account::MinusMyMoney(int minus)
{
	myMoney -= minus;
}

int Account::GetAccID() const
{
	return Accid;
}

int Account::GetMyMoney() const
{
	return myMoney;
}