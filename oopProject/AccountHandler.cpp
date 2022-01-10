/*
	�����̸� : AccountHandler.cpp
	�ۼ��� : �̼���
	������Ʈ ���� : [2020.11.02], ���Ϲ��� : 0.7
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
	cout << "1. ��  ��  ��  ��" << endl;
	cout << "2. ��          ��" << endl;
	cout << "3. ��          ��" << endl;
	cout << "4. ��������  ���" << endl;
	cout << "5. ���α׷�  ����" << endl;
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

	cout << "[������������]" << endl;
	cout << "1. ���뿹�ݰ���, 2. �ſ�ŷڰ���" << endl;
	cin >> choiceAcc;

	while (c_num != 1)
	{
		cout << "���� ID : ";
		cin >> id;

		if (count != 0)
		{
			for (int i = 0; i < count; i++)
			{
				if (pAcc[i]->GetAccID() == id)
				{
					cout << "���°� �ߺ��˴ϴ�. �ٽ� �����ϼ���." << endl;
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

	cout << "�̸� : ";
	cin >> name;

	cout << "�Աݾ� : ";
	cin >> money;

	if (choiceAcc == 1)
	{
		cout << "������: ";
		cin >> rate;
		pAcc[count++] = new NormalAccount(id, name, money, rate);
	}
	else if (choiceAcc == 2)
	{
		cout << "������: ";
		cin >> rate;
		cout << "�ſ���(1toA, 2toB, 3toC): ";
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
		cout << "���¹�ȣ�� �Է����ּ���." << endl;
		cin >> ID;

		while (chk != true)
		{
			if (pAcc[i]->GetAccID() == ID)
			{
				cout << "-----��������------" << endl;
				pAcc[i]->ShowMyInfo();
				cout << "-------------------" << endl;
				while (1)
				{
					try
					{
						cout << "�Ա��� �ݾ��� �Է����ּ��� :";
						cin >> Add_money;
						if (Add_money < 0)
							throw WithdrawException(Add_money);
						else
						{
							pAcc[i]->PlusMyMoney(Add_money);
							cout << "�ԱݵǾ����ϴ�. �Ա� �� �ݾ��� " << pAcc[i]->GetMyMoney() << "�Դϴ�." << endl;
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
		if (chk == false) cout << "���������� �����ϴ�. �ٽ� �Է����ּ���" << endl;
	}
}

void AccountHandler::PayMyMoney(void)
{
	int ID, Sub_money;
	bool chk = false;
	int i = 0;

	while (chk != true)
	{
		cout << "���¹�ȣ�� �Է����ּ���." << endl;
		cin >> ID;

		while (chk != true)
		{
			if (pAcc[i]->GetAccID() == ID)
			{
				cout << "-----��������------" << endl;
				pAcc[i]->ShowMyInfo();
				cout << "-------------------" << endl;

				while (1)
				{
					cout << "����� �ݾ��� �Է����ּ��� :";
					cin >> Sub_money;
					try 
					{
						if (Sub_money > pAcc[i]->GetMyMoney())
						{
							cout << "�ܾ��� �����մϴ�." << endl;
							throw DepositException(Sub_money);
						}
						else
						{
							pAcc[i]->MinusMyMoney(Sub_money);
							cout << "��ݵǾ����ϴ�. ��� �� �ݾ��� " << pAcc[i]->GetMyMoney() << "�Դϴ�." << endl;
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
		if (chk == false) cout << "���������� �����ϴ�. �ٽ� �Է����ּ���" << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < 100; i++)
	{
		delete pAcc[i];
	}
}