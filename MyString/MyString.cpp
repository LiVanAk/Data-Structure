#include "MyString.hpp"
#include <cstring>

// 私有辅助函数
void MyString::resize(size_t new_capacity) {
// 实现重新分配内存的逻辑
    // 新容量小于当前已经使用的空间大小，直接返回
    if (new_capacity < size_ + 1) {
        return;
    }
    // 分配新内存
    char* new_data_ = new char[new_capacity];
    // 当原内存存在数据时复制到新内存
    if (data_ != nullptr) {
        strcpy(new_data_, data_);
        delete[] data_;
    }
    data_ = new_data_;
    capacity_ = new_capacity;
    // size_不需要更新，因为字符串本身大小并未发生变化，仅分配的内存空间发生了变化
}

// 构造函数
// 默认构造函数
MyString::MyString() : data_(new char[1]), size_(0), capacity_(1) {
    data_[0] = '\0';
}
// 从字符串构造
MyString::MyString(const char* str) : data_(new char[strlen(str)+1]), size_(strlen(str)), capacity_(strlen(str)+1) {
    strcpy(data_, str);
}
// 拷贝构造函数
MyString::MyString(const MyString& other) : data_(new char[other.capacity_]), size_(other.size_), capacity_(other.capacity_) {
    strcpy(data_, other.data_);
}
// 移动构造函数
MyString::MyString(MyString&& other) : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

// 析构函数
MyString::~MyString() {
    delete[] data_;
}

// 赋值运算符
MyString& MyString::operator=(const MyString& other) {
    // 实现拷贝赋值运算符
    if (this != &other) {
        if (capacity_ < other.size_) {
            resize(other.size_ + 1);
            strcpy(data_, other.data_);
            size_ = other.size_;
        }
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) {
    // 实现移动赋值运算符
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

// 访问元素
char& MyString::operator[](size_t index) {
    // 实现下标运算符
    return data_[index];
}

const char& MyString::operator[](size_t index) const {
    // 实现const下标运算符
    return data_[index];
}

// 修改字符串
void MyString::append(const char* str) {
    // 实现追加C风格字符串

}

void MyString::append(const MyString& other) {
    // 实现追加MyString对象
}

MyString& MyString::operator+=(const char* str) {
    // 实现+=运算符(C风格字符串版本)
    if (capacity_ < size_ + strlen(str)) {
        resize(size_ + strlen(str) + 1);
    }
    return *this;
}

MyString& MyString::operator+=(const MyString& other) {
    // 实现+=运算符(MyString版本)
    return *this;
}

// 比较字符串
bool MyString::operator==(const MyString& other) const {
    // 实现相等比较
    return false;
}

bool MyString::operator!=(const MyString& other) const {
    // 实现不相等比较
    return false;
}

bool MyString::operator<(const MyString& other) const {
    // 实现小于比较
    return false;
}

bool MyString::operator>(const MyString& other) const {
    // 实现大于比较
    return false;
}

// 其他操作
MyString MyString::substr(size_t pos, size_t len) const {
    // 实现子串获取
    return MyString();
}

size_t MyString::find(char ch) const {
    // 实现查找字符
    return 0;
}

size_t MyString::find(const MyString& other) const {
    // 实现查找字符串
    return 0;
}

void MyString::swap(MyString& other) {
    // 实现交换
}

void MyString::clear() {
    // 实现清空字符串
}

// 非成员函数
MyString operator+(const MyString& lhs, const MyString& rhs) {
    // 实现+运算符(MyString + MyString)
    return MyString();
}

MyString operator+(const MyString& lhs, const char* rhs) {
    // 实现+运算符(MyString + C风格字符串)
    return MyString();
}

MyString operator+(const char* lhs, const MyString& rhs) {
    // 实现+运算符(C风格字符串 + MyString)
    return MyString();
}