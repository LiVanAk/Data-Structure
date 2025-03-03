#ifndef MY_STRING_HPP
#define MY_STRING_HPP

#include <cstddef>

class MyString {
private:
    char* data_;
    size_t size_;
    size_t capacity_;

    void resize(size_t new_capacity);

public:
    // 构造函数
    MyString();                         // 默认构造函数
    MyString(const char* str);          // 从字符串构造
    MyString(const MyString& other);    // 拷贝构造函数
    MyString(MyString&& other);         // 移动构造函数

    // 析构函数
    ~MyString();

    // 赋值运算符
    MyString& operator=(const MyString& other);    // 拷贝赋值运算符
    MyString& operator=(MyString&& other);         // 移动赋值运算符

    // 访问元素
    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    // 容量
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    // 修改字符串
    void append(const char* str);                   // 追加字符串
    void append(const MyString& other);
    MyString& operator+=(const char* str);
    MyString& operator+=(const MyString& other);

    // 比较字符串
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;

    // 其他操作
    MyString substr(size_t pos, size_t len) const;   // 返回子串
    size_t find(char ch) const;                      // 查找字符
    size_t find(const MyString& other) const;        // 查找字符串
    void swap(MyString& other);                      // 交换字符串
    const char* c_str() const { return data_; }      // 返回C风格字符串
    void clear();                                    // 清空字符串

};

// 非成员函数
MyString operator+(const MyString& lhs, const MyString& rhs);
MyString operator+(const MyString& lhs, const char* rhs);
MyString operator+(const char* lhs, const MyString& rhs);


#endif