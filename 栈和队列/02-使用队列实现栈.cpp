//
// Created by mengjiale on 2018/5/13.
//

#include <iostream>
#include <queue>

class myStack {
private:
    std::queue<int> temp;
    std::queue<int> data;

public:
    myStack()
    {

    }

    /**
     * 元素压栈
     * @param x
     */
    void push(int x)
    {
        temp.push(x);
        while (!data.empty()) {
            temp.push(data.front());
            data.pop();
        }
        while (!temp.empty()) {
            data.push(temp.front());
            temp.pop();
        }
    }
    /**
     * 弹出栈顶元素
     */
    void pop()
    {
        if (data.empty())
            return;
        else
            data.pop();
    }
    /**
     * 获取栈顶元素
     * @return
     */
    int top()
    {
        int res = data.front();
    }

    /**
     * 判栈空
     * @return
     */
    bool empty()
    {
        if (data.empty())
            return true;
        else
            return false;
    }

};

int main()
{
    myStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
}