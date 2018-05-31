// Author: Monk 
// Date: 2018/5/31.
// Description: 
#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>> &num)
    {
        int row = num.size();
        int column = num[0].size();
        std::vector<std::vector<int>> dp(row, std::vector<int>(column, 0));
        dp[0][0] = num[0][0];
        for (int i = 1; i < column; i++) {  // 向右走
            dp[0][i] = dp[0][i - 1] + num[0][i];
        }
        for (int i = 1; i < row; i++) {  // 向下走
            dp[i][0] = dp[i - 1][0] + num[i][0];
            for (int j = 1; j < column; j++) {
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + num[i][j];
            }
        }
        return dp[row-1][column-1];
    }
};

int main()
{

}
