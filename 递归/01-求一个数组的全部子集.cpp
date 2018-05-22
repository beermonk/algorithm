//
// Created by mengjiale on 2018/5/19.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subset(std::vector<int> &num)
    {
        std::vector<std::vector<int>> res;  // 用来存放最后的所有子集的数组
        std::vector<int> items;  // 用来生成子集的数组

        return res;
    }
};

int main()
{
    std::vector<int> nums{1, 2, 3};
    std::vector<std::vector<int>> res;
    Solution solve;
    res = solve.subset(nums);
    for (auto i : res) {
        for (auto j : i) {
            std::cout << j << std::endl;
        }
    }
}