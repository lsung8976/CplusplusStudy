/*
	파일이름 : AccountHandler.cpp
	작성자 : 이성준
	업데이트 정보 : [2020.11.02], 파일버젼 : 0.7
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountException.h"

AccountHandler::AccountHandler() : count(0) {}

void AccountHandler::InitPrt(void)
{
	cout << "------Menu-------" << endl;
	cout << "1. 계  좌  개  설" << endl;
	cout << "2. 입          금" << endl;
	cout << "3. 출          금" << endl;
	cout << "4. 계좌정보  출력" << endl;
	cout << "5. 프로그램  종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;
	int money;
	String name;

	int c_num = 0;
	int choiceAcc;
	int rate;
	int level;

	cout << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌, 2. 신용신뢰계좌" << endl;
	cin >> choiceAcc;

	while (c_num != 1)
	{
		cout << "계좌 ID : ";
		cin >> id;

		if (count != 0)
		{
			for (int i = 0; i < count; i++)
			{
				if (pAcc[i]->GetAccID() == id)
				{
					cout << "계좌가 중복됩니다. 다시 개설하세요." << endl;
					c_num = 0;
					break;
				}
				else
				{
					c_num = 1;
				}
			}
		}
		else c_num = 1;
	}

	cout << "이름 : ";
	cin >> name;

	cout << "입금액 : ";
	cin >> money;

	if (choiceAcc == 1)
	{
		cout << "이자율: ";
		cin >> rate;
		pAcc[count++] = new NormalAccount(id, name, money, rate);
	}
	else if (choiceAcc == 2)
	{
		cout << "이자율: ";
		cin >> rate;
		cout << "신용등급(1toA, 2toB, 3toC): ";
		cin >> level;
		switch (level)
		{
		case 1:
			pAcc[count++] = new HighCreditAccount(id, name, money, rate, CRDIT_LEVEL::A);
			break;
		case 2:
			pAcc[count++] = new HighCreditAccount(id, name, money, rate, CRDIT_LEVEL::B);
			break;
		case 3:
			pAcc[count++] = new HighCreditAccount(id, name, money, rate, CRDIT_LEVEL::C);
			break;
		}

	}
}

void AccountHandler::AccPrt(void)
{
	for (int i = 0; i < count; i++)
	{
		pAcc[i]->ShowMyInfo();
	}

}

void AccountHandler::ReciptMyMoney(void)
{
	int ID, Add_money;
	bool chk = false;
	int i = 0;

	while (chk != true)
	{
		cout << "계좌번호를 입력해주세요." << endl;
		cin >> ID;

		while (chk != true)
		{
			if (pAcc[i]->GetAccID() == ID)
			{
				cout << "-----계좌정보------" << endl;
				pAcc[i]->ShowMyInfo();
				cout << "-------------------" << endl;
				while (1)
				{
					try
					{
						cout << "입금할 금액을 입력해주세요 :";
						cin >> Add_money;
						if (Add_money < 0)
							throw WithdrawException(Add_money);
						else
						{
							pAcc[i]->PlusMyMoney(Add_money);
							cout << "입금되었습니다. 입금 후 금액은 " << pAcc[i]->GetMyMoney() << "입니다." << endl;
							chk = true;
							break;
						}
					}
					catch (Exception& expn)
					{
						expn.ShowException();
					}
				}
			}
			else
			{
				if (i == count) break;
				i++;
			}
		}
		if (chk == false) cout << "계좌정보가 없습니다. 다시 입력해주세요" << endl;
	}
}

void AccountHandler::PayMyMoney(void)
{
	int ID, Sub_money;
	bool chk = false;
	int i = 0;

	while (chk != true)
	{
		cout << "계좌번호를 입력해주세요." << endl;
		cin >> ID;

		while (chk != true)
		{
			if (pAcc[i]->GetAccID() == ID)
			{
				cout << "-----계좌정보------" << endl;
				pAcc[i]->ShowMyInfo();
				cout << "-------------------" << endl;

				while (1)
				{
					cout << "출금할 금액을 입력해주세요 :";
					cin >> Sub_money;
					try 
					{
						if (Sub_money > pAcc[i]->GetMyMoney())
						{
							cout << "잔액이 부족합니다." << endl;
							throw DepositException(Sub_money);
						}
						else
						{
							pAcc[i]->MinusMyMoney(Sub_money);
							cout << "출금되었습니다. 출금 후 금액은 " << pAcc[i]->GetMyMoney() << "입니다." << endl;
							chk = true;
							break;
						}
					}
					catch (Exception& expn)
					{
						expn.ShowException();
					}
				}			
			}
			else
			{
				if (i == count) break;
				i++;
			}
		}
		if (chk == false) cout << "계좌정보가 없습니다. 다시 입력해주세요" << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < 100; i++)
	{
		delete pAcc[i];
	}
}