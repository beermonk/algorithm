// Author: Monk 
// Date: 2018/5/30.
// Description: 
#include <iostream>
#include <vector>

class Solution {
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        std::vector<int> dp;
        for (int i = 0; i <= amount; i++) {
            dp.push_back(-1);
        }
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                    if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) {
                        dp[i] = dp[i - coins[j]] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main()
{
    std::vector<int> coins{1, 2, 5, 7, 10};
    int amount = 12;
    Solution solve;
    int res = solve.coinChange(coins, amount);
    std::cout << res << std::endl;
}