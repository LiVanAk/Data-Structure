#ifndef HEAP_HPP
#define HEAP_HPP
#include <vector>

/* 大顶堆 */
template <typename T>
class heap {
public:
    /* 访问堆顶元素 */
    T peek() {
        return data[0];
    }

    /* 元素入堆 */
    void push(T val) {
        /* 将元素存入数组，即添加至堆底 */
        data.push_back(val);
        /* 修复从插入节点到根节点路径上的各个节点，即向上堆化 */
        shiftUp(size()-1);
    }

    /* 元素出堆 */
    void pop() {
        /* 判空处理 */
        if (empty()) {
            return;
        }
        /* 交换堆顶元素与堆底元素 */
        swap(data[0], data[size()-1]);
        /* 删除堆底，即原本的堆顶元素 */
        data.pop_back();
        /* 从根节点自顶至底执行堆化 */
        shiftDown(0);
    }

    /* 返回堆大小 */
    int size() {
        return data.size();
    }

    /* 判断堆是否为空 */
    bool empty() {
        return data.size() == 0;
    }
private:
    /* 实际存储的数组 */
    std::vector<T> data;

    /* 获取左子节点的索引 */
    int left(int i) {
        return 2*i + 1;
    }

    /* 获取右子节点的索引 */
    int right(int i) {
        return 2*i + 2;
    }

    /* 获取父节点的索引 */
    int parent(int i) {
        return (i-1) / 2;
    }

    /* 从节点i开始，从底至顶执行堆化 */
    void shiftUp(int i) {
        /* 比较i节点与其父节点的值 */
        while (data[parent(i)] < data[i]) {
            /* 交换两个节点 */ 
            swap(data[parent(i)], data[i]);
            /* 更新节点索引 */
            i = parent(i);
        }
    }

    /* 从节点i开始，从顶至底执行堆化 */
    void shiftDown(int i) {
        while (true) {
            /* 找到节点i和其子节点中最大节点 */
            int l = left(i), r = right(i), goal = i;
            if (l < size() && data[l] > data[goal]) {
                goal = l;
            }
            if (r < size() && data[r] > data[goal]) {
                goal = r;
            }
            /* 若节点i最大，或索引l，r越界，则无需继续堆化，跳出循环 */
            if (goal == i) {
                break;
            }
            /* 否则交换元素，继续向下堆化 */
            swap(data[i], data[goal]);
            i = goal;
        }
    }

    /* 实现元素交换 */
    void swap(T& val1, T& val2) {
        T tmp = val1;
        val1 = val2;
        val2 = tmp;
    }
};

#endif