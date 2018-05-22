//
// Created by mengjiale on 2018/5/14.
//

#include <iostream>
#include <stack>

class myQueue {
private:
    std::stack<int> temp_stack;
    std::stack<int> data_stack;
public:
    /**
     * 元素入队列
     * @param x
     */
    void push(int x)
    {
        // 入栈的基本过程，当有新元素入栈的时候，先将data_stack中的元素入temp_stack中，然后将新元素入data栈，
        // 随后将temp_stack中的元素入data_stack栈
        while (!data_stack.empty()) {
            temp_stack.push(data_stack.top());
            data_stack.pop();
        }
        data_stack.push(x);
        while (!temp_stack.empty()) {
            data_stack.push(temp_stack.top());
            temp_stack.pop();
        }
    }
    /**
     * 获取队头元素
     * @return
     */
    int front()
    {
        int res = data_stack.top();
        return res;
    }
    /**
     * 弹出队头元素
     */
    void pop()
    {
        data_stack.pop();
    }

    /**
     * 判栈空
     * @return
     */
    bool empty()
    {
        return data_stack.empty();
    }
};

int main()
{
    myQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty()) {
        std::cout << q.front() << std::endl;
        q.pop();
    }
}
