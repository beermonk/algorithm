//
// Created by mengjiale on 2018/5/15.
//

#include <iostream>
#include <queue>

int main()
{
    // STL优先级队列
    std::priority_queue<int> big_heap;  // 优先级队列叫做二叉堆, 默认构造最大堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_heap;  // 最小堆的构造方法
    std::priority_queue<int, std::vector<int>, std::less<int>> big_heap2;  // 最大堆的构造方法

    big_heap.push(6);
    big_heap.push(10);
    big_heap.push(1);
    big_heap.push(7);
    big_heap.push(99);
    big_heap.push(4);
    big_heap.push(33);

    // 获取堆顶元素即最大值
    std::cout << big_heap.top() << std::endl;
    // 弹出堆顶元素
    big_heap.pop();
    std::cout << big_heap.top() << std::endl;
    // 返回堆中元素的个数
    int res = big_heap.size();
    std::cout << res << std::endl;


}
