//
// Created by mengjiale on 2018/5/18.
//

#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.first < b.first;
}

class Solution {
public:
    int shootNumber(std::vector<std::pair<int, int>> &num)
    {
        // 首先将气球按照左侧元素的大小进行排序
        std::sort(num.begin(), num.end(), cmp);
        int shoot_number = 1;  // 射击手的数量
        // 射击区间
        int shoot_begin = num[0].first;
        int shoot_end = num[0].second;

        for (int i = 1; i < num.size(); i++) {  // 遍历每一个气球，更新射击区间和射击手的数量
            if (num[i].first <= shoot_end) {
                shoot_begin = num[i].first;  // 更新射击区间左端点
                if (num[i].second < shoot_end) {  // 更新射击区间右端点
                    shoot_end = num[i].second;
                }
            }
            else {  // 需要增加一个新的射击区间
                shoot_number++;
                shoot_begin = num[i].first;
                shoot_end = num[i].second;
            }
        }
        return shoot_number;
    }
};

int main()
{
    Solution solve;
    std::vector<std::pair<int, int>> num{{10, 16},
                                         {2,  8},
                                         {1,  6},
                                         {7,  12}};

    int res = solve.shootNumber(num);
    std::cout << res << std::endl;
}
