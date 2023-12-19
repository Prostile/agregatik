#ifndef CSTR_T
#define CSTR_T
#include <iostream>
#include <vector>
#include <String>
using namespace std;

class CStr
{
	vector<char> string;
	vector<char> generate(int length);
public:
	CStr();
	CStr(char* str);
	CStr(const char* str);
	CStr(int length);
	CStr(const CStr& obj);
	~CStr();
	CStr& operator=(CStr& obj);
	CStr& operator=(char* str);
	bool operator>(CStr& obj);
	bool operator==(CStr& obj);
	int get_length();
	int operator[](int index);
	friend std::ostream& operator<<(std::ostream& stream, CStr& obj);
};
#endif