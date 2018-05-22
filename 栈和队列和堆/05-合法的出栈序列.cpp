//
// Created by mengjiale on 2018/5/14.
//

#include <iostream>
#include <queue>
#include <stack>

class Solution {
public:
    bool checkIsValidOrder(std::queue<int> &order)
    {
        std::stack<int> s;  // 模拟栈
        int n = order.size();

        for (int i = 1; i <= n; i++) {
            // i元素入栈
            s.push(i);
            // 比较栈顶元素和队首元素
            while (!s.empty() && s.top() == order.front()) {
                s.pop();
                order.pop();
            }
        }
        if (!s.empty())
            return false;
        return true;
    }
};

int main()
{
    Solution solu;
    std::queue<int> queue2;  // 待检验序列

    queue2.push(3);
    queue2.push(2);
    queue2.push(5);
    queue2.push(4);
    queue2.push(1);

    bool res = solu.checkIsValidOrder(queue2);
    if (res)
        std::cout << "序列合法" << std::endl;
    else
        std::cout << "序列不和法" << std::endl;

}
