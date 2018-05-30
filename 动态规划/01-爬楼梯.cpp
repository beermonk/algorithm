// 
// Created by Monk on 2018/5/29.
//
#include <iostream>
#include <vector>

class Solution {
    public:
        int climbStairs(int n)
        {
            std::vector<int> dp(n+3, 0);
            dp[1] = 1;
            dp[2] = 2;
            for (int i = 3; i <= n; i++) {
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n];
        }
};

int main()
{
    Solution solve;
    int res = solve.climbStairs(10);
    std::cout << res << std::endl;
}
