#pragma once
#include "CString.h"
#include <vector>

class CStrArray
{
	vector<CStr> arr;
	int length;


	void swap(CStr& a, CStr& b) {
		CStr c = a;
		a = b;
		b = c;
	}
public:
	CStrArray(int leng);
	~CStrArray();
	CStr& operator[](int index);
	void sort_by_content();
	void sort_by_length();
	int bin_search(CStr& obj);
	bool check_sort();
	friend ostream& operator<<(ostream& stream, CStrArray& obj);
};
