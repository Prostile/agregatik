#include "CStringArray.h"


CStrArray::CStrArray(int leng) {
	length = leng;
	for (int i = 0; i < leng; i++) {
		CStr newCStr;
		arr.push_back(newCStr);
	}
}

CStrArray::~CStrArray() {
	arr.clear();
}

CStr& CStrArray::operator[](int index) {
	return arr[index];
}

void CStrArray::sort_by_content() {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size() - i - 1; j++) {
			{
				int k = 0;
				int min_len = min(arr[j].get_length(), arr[j + 1].get_length());
				while (k < min_len)
				{
					if (arr[j][k] > arr[j + 1][k]) {
						swap(arr[j], arr[j + 1]);
						k = min_len;
					}
					else if (arr[j][k] < arr[j + 1][k]) k = min_len;
					else k++;
				}
			}
		}
	}
}

void CStrArray::sort_by_length() {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size() - i - 1; j++) {
			if (arr[j].get_length() > arr[j + 1].get_length()) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int CStrArray::bin_search(CStr& obj) {
	int start = 0;
	int end = length - 1;
	while (start <= end) {
		int n = ((start + end) / 2) + ((start + end) % 2);
		if (obj == arr[n]) return n;
		if (arr[n] > obj) end = n - 1;
		else start = n + 1;
	}
	return -1;
}

bool CStrArray::check_sort()
{
	int minlength = 100;
	for (int i = 0; i < arr.size(); i++)
	{
		if (minlength > arr[i].get_length())minlength = arr[i].get_length();
	}
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int k = 0;
		if (arr[i][k] < arr[i+1][k]);
		else if (arr[i][k] == arr[i+1][k])
			while (k < minlength)
			{
				if (arr[i][k] < arr[i+1][k]) k = minlength;
				else if (arr[i][k] > arr[i+1][k]) return false;
				else k++;
			}
		else return false;
	}
	return true;
}

ostream& operator<<(ostream& stream, CStrArray& obj)
{
	if (obj.length > 50) {
		stream << "массив слишком велик";
		return stream;
	}
	for (int i = 0; i < obj.length; i++) stream << obj.arr[i] << " ";
	return stream;
}