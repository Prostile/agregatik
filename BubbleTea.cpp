#include <iostream>
#include "CStringArray.h"

int main() {
    setlocale(LC_ALL, "rus");

    int arrayLength = 8; 
    CStrArray strArray(arrayLength);
    CStr searchStr(strArray[1]);

    std::cout << "Несортированный массив:" << std::endl;
    std::cout << strArray << std::endl;

    strArray.sort_by_length();
    std::cout << "Сортированный по длине:" << std::endl;
    std::cout << strArray << std::endl;

    strArray.sort_by_content();
    std::cout << "Сортированный по содержимому:" << std::endl;
    std::cout << strArray << std::endl;

    cout << "сортировка по содержимому выполнена: ";
    if (strArray.check_sort()) cout << "правильно" << endl;
    else cout << "неправильно" << endl;

    int index = strArray.bin_search(searchStr);
    cout << "Поиск строки " << searchStr << endl;
    if (index != -1) std::cout << "Строка найдена, ее индекс: " << index << std::endl;
    else  std::cout << "Строка не найдена" << std::endl;
}
