#include "CString.h"
#include <cstdlib> 

vector<char> CStr::generate(int length) {
	vector<char> newStr;
	for (int i = 0; i < length; i++) {
		newStr.push_back('A' + rand() % 26);
	}
	return newStr;
}

CStr::CStr() {
	int random = (rand() % 20) + 1;
	string = generate(random);
}

CStr::CStr(char* str) {
	vector<char> string(str, str + strlen(str));
	string[strlen(str) + 1] = '0';
	CStr::string = string;

}
CStr::CStr(const char* str) {
	vector<char> string(str, str + strlen(str));
	CStr::string = string;

}

CStr::CStr(int length) {
	string = generate(rand() % 20 + 1);
}

CStr::CStr(const CStr& obj) :string(obj.string) {}

CStr::~CStr() {
	string.clear();
}

CStr& CStr::operator=(CStr& obj) {
	string = obj.string;
	return *this;
}

CStr& CStr::operator=(char* str) {
	vector<char> string(str, str + strlen(str));
	this->string = string;
	return *this;
}

bool CStr::operator>(CStr& obj) {
	if (&obj == this) {
		return true;
	}
	int min_str = min(string.size(), obj.string.size());
	for (int i = 0; i < min_str; i++) {
		if (string[i] < obj.string[i]) {
			return false;
		}
		return true;
	}
	return false;
}

int CStr::get_length() {
	return string.size();
}


ostream& operator<<(ostream& stream, CStr& obj) {
	for (int i = 0; i < obj.get_length(); i++) {
		stream << obj.string[i];
	}
	return stream;
}

bool CStr::operator==(CStr& obj) {
	if (&obj == this) {
		return true;
	}
	if (string.size() == obj.string.size())
		for (int i = 0; i < string.size(); i++) {
			if (string[i] != obj.string[i]) {
				return false;
			}
			return true;
		}
	return false;
}

int CStr::operator[](int index)
{
	return string[index];
}