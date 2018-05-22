//
// Created by mengjiale on 2018/5/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     *
     * @param g  孩子的需求
     * @param s  糖果的大小
     * @return
     */
    int findContentChildren(std::vector<int> &g, std::vector<int> &s)
    {
        // 对两个数组进行排序
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;

        while (child < g.size() && cookie < s.size()) {
            if (g[child] <= s[cookie]) {  // 当孩子的满足因子小于糖果的大小时
                child++;
            }
            cookie++;
        }
        return child;
    }
};

int main()
{
    Solution slove;
    std::vector<int> g {5, 10, 2, 9, 15, 9};
    std::vector<int> s {6, 1, 20, 3, 8};
    int res = slove.findContentChildren(g, s);
    std::cout << res << std::endl;
}