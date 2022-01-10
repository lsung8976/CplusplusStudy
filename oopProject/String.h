#ifndef __STRING_H__
#define __STRING_H__
#include "BankingCommonDecl.h"

class String
{
private:
	char* ptr;
	int len;
public:
	String();
	String(const char* str);
	String(const String& cpy);
	String& operator=(const String& cpy);
	String operator+(const String& src);
	String& operator+=(const String& src);
	bool operator==(const String& s1);
	friend ostream& operator<<(ostream& os, const String& s1);
	friend istream& operator>>(istream& os, String& s1);
public:
	void ShowString() const;
	~String();
};

#endif __STRING_H__