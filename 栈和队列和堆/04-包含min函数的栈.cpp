//
// Created by mengjiale on 2018/5/14.
//

#include <iostream>
#include <stack>

class myStack {
private:
    std::stack<int> data_stack;
    std::stack<int> temp_stack;
public:
    void push(int x)
    {
        data_stack.push(x);

        if (temp_stack.empty()) // 如果temp_stack栈为空，则x直接入最小值栈
            temp_stack.push(x);
        else {
            if (temp_stack.top() < x)  // 判断最小值栈的栈顶元素和待插入的元素的大小，以此来更新最小值栈
                x = temp_stack.top();
            temp_stack.push(x);
        }
    }

    /*获取栈中的最小元素*/
    int getMin()
    {
        return temp_stack.top();
    }

    int top()
    {
        int res = data_stack.top();
    }

    void pop()
    {
        data_stack.pop();
        temp_stack.pop();
    }

};

int main()
{
    myStack s;
    s.push(1);
    s.push(2);
    s.push(-3);
    s.push(3);
    s.push(4);
    s.push(5);

    std::cout << s.getMin() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.getMin() << std::endl;
}
