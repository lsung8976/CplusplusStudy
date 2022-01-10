#include "String.h"

String::String()
{
	ptr = NULL;
	len = 0;
}
String::String(const char* str)
	:len(strlen(str) + 1)
{
	ptr = new char[len];
	strcpy_s(ptr, len, str);
}
String::String(const String& cpy)
{
	ptr = new char[cpy.len];
	strcpy_s(ptr, cpy.len, cpy.ptr);
	len = cpy.len;
}

String& String::operator=(const String& cpy)
{
	if (ptr != NULL)
		delete[] ptr;
	len = cpy.len;
	ptr = new char[len];
	strcpy_s(ptr, len, cpy.ptr);
	return *this;
}

String String::operator+(const String& src)
{
	char stringcpy[100];
	strcpy_s(stringcpy, len, ptr);
	strcat_s(stringcpy, len + src.len, src.ptr);
	String addString(stringcpy);
	return addString;
}

String& String::operator+=(const String& src)
{
	char addstring[100];					//���ο� ���ڿ� ����
	strcpy_s(addstring, len, ptr);		//���ڿ� �����Ϳ� ù��°���ڿ� ����
	len += (src.len - 1);			//�þ ���̸�ŭ ���ڿ� ���� ����
	strcat_s(addstring, len, src.ptr);	//�����Ҵ�� �޸𸮿� ���ڿ� �̾���̱� & ���� �ø���

	if (ptr != NULL)
		delete[] ptr;						//���� ��ü ���ڿ� ������ ����
	ptr = new char[len];				//�����Ҵ�
	strcpy_s(ptr, len, addstring);		//���θ������ ������ ���ڿ� �ֱ� 

	return *this;
}

bool String::operator==(const String& s1)
{
	if (strcmp(ptr, s1.ptr))
		return false;
	else
		return true;
}

void String::ShowString() const
{
	cout << ptr << endl;
}
String::~String()
{
	if (ptr != NULL)
		delete[] ptr;
}

ostream& operator<<(ostream& os, const String& s1)
{
	os << s1.ptr;
	return os;
}
istream& operator>>(istream& os, String& s1)
{
	char temp[100];
	cin >> temp;
	s1 = String(temp);
	return os;
}