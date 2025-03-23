#include "MyString.hpp"
#include <iostream>

int main() {
    MyString str1;
    MyString str2("Hello MyString");
    MyString str3(str2);
    MyString str4 = std::move(str3);
    std::cout << str2 << std::endl;
    str3 = "asjdlka";
    std::cout << str3 << std::endl;
    str2.append("asjdlkdasdlk");
    std::cout << str2;
    return 0;
}