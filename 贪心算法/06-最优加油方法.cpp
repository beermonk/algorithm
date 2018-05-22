//
// Created by mengjiale on 2018/5/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.first > b.first;
}

class Solution {
public:
    int getMinimumStop(std::vector<std::pair<int, int>> &stop, int P, int L)
    {
        int minimumStop = 0;
        std::priority_queue<int> Q;  // 用来存放油量的最大堆
        stop.push_back(std::make_pair(0, 0));  // 将终点作为一个停靠点添加到stop中

        std::sort(stop.begin(), stop.end(), cmp);  // 将停靠点到终点的距离大小排序

        for (int i = 0; i < stop.size(); i++) {  // 遍历各个停靠点
            int distance = L - stop[i].first;
            while (!Q.empty() && P < distance) {  // 如果剩余油量不够到下一个加油站则要加油
                P += Q.top();
                Q.pop();
                minimumStop++;
            }
            if (Q.empty() && P < distance) {
                return -1;
            }
            P = P - distance;
            L = stop[i].first;
            Q.push(stop[i].second);
        }

        return minimumStop;
    }
};

int main()
{
    std::vector<std::pair<int, int>> num{{15, 2},
                                         {11, 5},
                                         {10, 3},
                                         {4,  4}};
    int distance = 25;  // 起点到终点的距离
    int gas = 16;  // 起始时候车的油量
    Solution solve;

    int res = solve.getMinimumStop(num, gas, distance);
    std::cout << res << std::endl;
}
