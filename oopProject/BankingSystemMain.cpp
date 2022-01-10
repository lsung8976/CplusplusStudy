/*
	파일이름 : BankingSystemMain.cpp
	작성자 : 이성준
	업데이트 정보 : [2020.11.26], 파일버젼 : 0.8
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

using namespace std;

int main()
{
	AccountHandler manager;

	int initnum = 0;

	while (initnum != 5)
	{
		manager.InitPrt();
		cin >> initnum;
		switch (initnum)
		{
		case 1: manager.MakeAccount();
			break;
		case 2: manager.ReciptMyMoney();
			break;
		case 3: manager.PayMyMoney();
			break;
		case 4: manager.AccPrt();
			break;
		case 5: cout << "프로그램을 종료합니다." << endl;
			break;
		default:
			cout << "Illegal selection" << endl;
		}
	}
}