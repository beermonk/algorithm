// Author: Monk 
// Date: 2018/5/30.
// Description: 
#include <iostream>
#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle)
    {
        std::vector<std::vector<int>> dp;  // 定义dp
        for (int i = 0; i < triangle.size(); i++) {  // dp初始化
            dp.push_back(std::vector<int>());
            for (int j = 0; j < triangle.size(); j++) {
                dp[i].push_back(0);
            }
        }
        for (int i = 0; i < triangle.size(); i++) {  // 边界状态值
            dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
        }

        for (int i = dp.size() - 2; i >= 0; i--) {
            for (int j = 0; j < dp[i].size(); j++) {
                dp[i][j] = std::min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];  // 状态方程
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution solve;
    std::vector<std::vector<int>> triangle{{2},
                                           {3, 4},
                                           {6, 5, 1},
                                           {4, 4, 8, 1}};
    int res = solve.minimumTotal(triangle);
    std::cout << res << std::endl;
}
