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
	char addstring[100];					//새로운 문자열 선언
	strcpy_s(addstring, len, ptr);		//문자열 포인터에 첫번째문자열 복사
	len += (src.len - 1);			//늘어난 길이만큼 문자열 길이 저장
	strcat_s(addstring, len, src.ptr);	//동적할당된 메모리에 문자열 이어붙이기 & 길이 늘리기

	if (ptr != NULL)
		delete[] ptr;						//본래 객체 문자열 포인터 제거
	ptr = new char[len];				//동적할당
	strcpy_s(ptr, len, addstring);		//새로만들어진 공간에 문자열 넣기 

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