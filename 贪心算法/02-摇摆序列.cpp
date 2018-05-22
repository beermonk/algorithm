//
// Created by mengjiale on 2018/5/15.
//

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * 使用状态机解决该问题
     * @param num
     * @return
     */
    int wiggleMaxLength(std::vector<int> &num)
    {
        // 初始的时候定义三个状态
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int STATE = BEGIN;
        int maxLength = 1;

        if (num.size() < 2) {  // 如果序列的元素个数小于2，直接为摇摆序列
            return num.size();
        }
        for (int i = 1; i < num.size(); i++) {
            switch (STATE) {
                case BEGIN:
                    if (num[i - 1] < num[i]) {
                        STATE = UP;
                        maxLength++;
                    }
                    else if (num[i - 1] > num[i]) {
                        STATE = DOWN;
                        maxLength++;
                    }
                    break;
                case UP:
                    if (num[i-1] > num[i]) {
                        STATE = DOWN;
                        maxLength++;
                    }
                    break;
                case DOWN:
                    if (num[i-1] < num[i]) {
                        STATE = UP;
                        maxLength++;
                    }
                    break;
            }
        }

        return maxLength;
    }
};

int main()
{
    std::vector<int> num{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};  // 最长子序列为：{1， 17， 5， 15， 5， 16， 8}
    Solution solve;
    int res1 = solve.wiggleMaxLength(num);
    std::cout << res1 << std::endl;
}
