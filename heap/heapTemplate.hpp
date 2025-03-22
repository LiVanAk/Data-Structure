#ifndef HEAP_HPP
#define HEAP_HPP
#include <vector>

/* 大顶堆 */
template <typename T>
class heap {
public:
    /* 访问堆顶元素 */
    T peek();

    /* 元素入堆 */
    void push(T val);

    /* 元素出堆 */
    void pop();

    /* 返回堆大小 */
    int size();

    /* 判断堆是否为空 */
    bool empty();
private:
    /* 实际存储的数组 */
    std::vector<T> data;

    /* 获取左子节点的索引 */
    int left(int i);

    /* 获取右子节点的索引 */
    int right(int i);

    /* 获取父节点的索引 */
    int parent(int i);

    /* 从节点i开始，从底至顶执行堆化 */
    void shiftUp(int i) ;

    /* 从节点i开始，从顶至底执行堆化 */
    void shiftDown(int i);

    /* 实现元素交换 */
    void swap(T& val1, T& val2);
};

#endif