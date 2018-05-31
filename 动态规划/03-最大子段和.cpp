// Author: Monk 
// Date: 2018/5/30.
// Description: 
#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int> &num)
    {
        std::vector<int> dp(num.size(), 0);
        dp[0] = num[0];
        int max_res = dp[0];

        for (int i = 1; i < num.size(); i++) {
            dp[i] = std::max(dp[i - 1] + num[i], num[i]);  // 状态转移方程
            if (max_res < dp[i]) {
                max_res = dp[i];
            }
        }
        return max_res;
    }
};

int main()
{
    std::vector<int> num{-1, 2, 3, -4, 4, 2, 8, 5};
    Solution solve;
    int res = solve.maxSubArray(num);
    std::cout << res << std::endl;
}
