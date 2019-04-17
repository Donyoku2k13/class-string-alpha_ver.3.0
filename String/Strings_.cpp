#include "Strings_.h"

string_::string_()
{
	this->cStr = nullptr;
	this->length = 0;
}

string_::string_(const string_ & str, size_t pos, size_t len)
{
	if (len==0||str.cStr==nullptr)	{
		this->cStr = nullptr;
		this->length = 0;
		return;
	}
	this->cStr = new char[len + 1];
	this->length = len;
	for (size_t i = pos; (i < pos+len)||(i<str.length); i++)
	{
		this->cStr[i - pos] = str.cStr[i];
	}
	this->cStr[len] = '\0';
}

string_::string_(const char * s)
{
	this->cStr = new char[strlen(s) + 1];
	strcpy_s(this->cStr, strlen(s) + 1, s);
	this->length = strlen(s);
}

string_::string_(const char * s, size_t n)
{
	this->cStr = new char[n + 1];
	strcpy_s(this->cStr, n+1 , s);
	this->length = n;
}

string_::string_(size_t n, char  c)
{
	this->cStr = new char[n + 1];
	for (size_t i = 0; i < n; i++)
		this->cStr[i] = c;
	this->cStr[n] = '\0';
	this->length = n;
}

string_::string_(const string_ & str)
{
	this->length = str.length;
	if (length==0)
	{
		this->cStr = nullptr;
		return;
	}
	this->cStr = new char[length + 1];
	strcpy_s(this->cStr,this->length + 1, str.cStr);
}

string_::~string_()
{
	if (cStr != nullptr)
	{
		delete[]this->cStr;
	}
	this->length = 0;
	this->cStr = nullptr;
}

string_ & string_::operator=(const string_ & str)
{
	if (this==&str)
	{
		return *this;
	}
	if (this->length==str.length)
	{
		strcpy_s(this->cStr, length + 1, str.cStr);
		return *this;
	}
	if (str.cStr==nullptr)
	{
		delete[]this->cStr;
		this->length = 0;
		this->cStr = nullptr;
		return *this;
	}
	else
	{
		delete[]this->cStr;
		this->length = str.length + 1;
		strcpy_s(this->cStr, length + 1, str.cStr);
	}
}

void string_::clear()
{
 this->~string_();
}

void string_::print()const
{
	cout << cStr << endl;
}
char& string_::operator[](int pos)
{
	return this->cStr[pos]; 
}

const char string_::operator[](int pos) const
{
	return this->cStr[pos];
}

string_ string_::operator+(string_ a, string_ b)
{
	string_ re
}

ostream & operator<<(ostream & os, const string_ & str)
{
	os << str.cStr;
	return os;
}

istream & operator>>(istream & is, string_ & str)
{
	cout << "enter string:" << endl;
	char s[1024];
	cin >> s;
	str.clear();
	str = new char[strlen(s) + 1];
	str.length = strlen(s);
	strcpy_s(str.cStr, str.length + 1, s);
}
