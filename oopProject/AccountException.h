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
		cout << "출금 금액 " << num << "은 잔액 보다 큽니다." << endl;
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
		cout << "입금 금액 " << num << "은 음수이므로 불가능합니다." << endl;
	}
};

#endif