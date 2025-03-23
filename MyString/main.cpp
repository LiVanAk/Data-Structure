#include "MyString.hpp"
#include <iostream>

int main() {
    MyString str1;
    MyString str2("Hello MyString/");
    MyString str3(str2);
    MyString str4 = std::move(str3);
    std::cout << str2 << std::endl;
    str3 = "Test MyString/";
    std::cout << str3 << std::endl;
    str2.append("Test MyString2/");
    std::cout << str2 << std::endl;
    str2 += str3;
    std::cout << str2 << std::endl;
    MyString s1 = "hello", s2 = "hellp";
    if (s1 > s2) {
        std::cout << ">";
    }
    else if (s1 == s2) {
        std::cout << "=";
    }
    else {
        std::cout << "<";
    }

    return 0;
}