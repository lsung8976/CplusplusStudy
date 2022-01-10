/*
	파일이름 : Account.cpp
	작성자 : 이성준
	업데이트 정보 : [2020.11.26], 파일버젼 : 0.8
*/

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int Accid, String Owner, int myMoney)
	:Accid(Accid), Owner(Owner), myMoney(myMoney)	{}

Account::Account(const Account& copy) // 복사 생성자 추가
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
	cout << "고객명 : " << Owner << endl;
	cout << "계좌번호 : " << Accid << endl;
	cout << "현재 잔액 :" << myMoney << endl;
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