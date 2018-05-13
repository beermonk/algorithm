//
// Created by mengjiale on 2018/5/13.
//

#include <iostream>
#include <stack>  // STL 栈
#include <queue>  // STL 队列

int main()
{
    // 栈的基本操作
    std::stack<int> s;
    if (s.empty()) {
        std::cout << "栈为空" << std::endl;
    }
    s.push(5);
    s.push(6);
    s.push(7);
    std::cout << "栈顶元素:" << s.top() << std::endl;
    s.pop();  // 弹出栈顶元素
    std::cout << "栈顶元素:" << s.top() << std::endl;
    std::cout << "栈中的元素个数:" << s.size() << std::endl;
    // 队列的基本操作
    std::queue<int> q;
    if (q.empty()) {  // 判断队列是否为空
        std::cout << "队列为空" << std::endl;
    }
    // 向栈中添加元素
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << "队列头部元素为:" << q.front() << std::endl;  // 返回队列头部元素
    std::cout << "队列尾部元素为:" << q.back() << std::endl;  // 返回队列尾部元素
    q.pop(); // 弹出队列头部元素
    std:: cout << "队列中的元素个数:" << q.size() << std::endl;  // 获取队列中元素的个数

}

