//
// Created by mengjiale on 2018/5/17.
//

#include <iostream>
#include <vector>

class Solution {
public:
    bool canJump(std::vector<int> &num)
    {
        // 构建能到达的最远的位置的数组
        std::vector<int> index;
        for (int i = 0; i < num.size(); i++) {
            index.push_back(num[i] + i);
        }

        int jump = 0;
        int max_index = index[0];
        while (jump < index.size() && jump <= max_index) {
            if (max_index < index[jump]) {
                max_index = index[jump];
            }
            jump++;
        }
        if (jump == index.size())  // 如果jump到达数组末尾，则返回true
            return true;
        else
            return false;

    }
    /**
     * 从0位置跳跃到最后一个位置需要的最少次数
     */
    int leastJump(std::vector<int> &num)
    {

    }


};

int main()
{
    std::vector<int> num{2, 3, 1, 1, 4};
    Solution solve;
    bool res = solve.canJump(num);
    std::cout << res << std::endl;
}