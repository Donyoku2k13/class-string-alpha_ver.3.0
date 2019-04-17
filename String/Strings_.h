#pragma once
#include <iostream>
using namespace std;
class string_
{
private:
	char *cStr;
	size_t length;
public:
	string_();
	
	string_(const string_&str, size_t pos, size_t len);
	string_(const char*s);
	string_(const char*s, size_t n);
	string_(size_t n, char c);

	string_(const string_& str);
	~string_();
	string_& operator=(const string_& str);
	void clear();
	void print()const;
	
	friend istream & operator>>(istream & is, string_ & obj);
	friend ostream & operator<<(ostream & os, const string_ & obj);
	
	char& operator[](int pos);
	const char operator[](int pos)const;
	
};


