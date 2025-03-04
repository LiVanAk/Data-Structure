#include "MyString.hpp"
#include <iostream>

int main() {
    MyString str1;
    MyString str2("Hello MyString");
    MyString str3(str2);
    MyString str4 = std::move(str3);
    return 0;
}