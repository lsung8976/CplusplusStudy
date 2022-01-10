#ifndef __ACCOUNT_EXCEPTINO_H__
#define __ACCOUNT_EXCEPTINO_H__

class Exception
{
public:
	virtual void ShowException() = 0;
};

class DepositException : public Exception
{
private:
	int num;
public:
	DepositException(int n) : num(n) {}
	void ShowException()
	{
		cout << "��� �ݾ� " << num << "�� �ܾ� ���� Ů�ϴ�." << endl;
	}
};

class WithdrawException : public Exception
{
private:
	int num;
public:
	WithdrawException(int n) : num(n) {}
	void ShowException()
	{
		cout << "�Ա� �ݾ� " << num << "�� �����̹Ƿ� �Ұ����մϴ�." << endl;
	}
};

#endif