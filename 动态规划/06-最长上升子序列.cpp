// Author: Monk 
// Date: 2018/5/30.
// Description: 
#include <iostream>
#include <vector>

class Solution {
public:
    int lenthOfLIS(std::vector<int> &num)
    {
        std::vector<int> dp(num.size(), 0);
        dp[0] = 1;
        int LIS = 1;

        for (int i = 0; i < dp.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (num[i] > num[j] && dp[i] < dp[j] + 1) {  // 求dp[i]
                    dp[i] = dp[j] + 1;
                }
            }
            if (LIS < dp[i]) {
                LIS = dp[i];
            }
        }
        return LIS;
    }

};
int main()
{
    std::vector<int> num {1, 3, 2, 3, 1, 4};
    Solution solve;
    int res = solve.lenthOfLIS(num);
    std::cout << res << std::endl;
}
