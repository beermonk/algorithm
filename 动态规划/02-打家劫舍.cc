#include <iostream>
#include <vector>

class Solution {
    public:
        int rot(std::vector<int> &nums)
        {
            if (nums.size() == 0) {
                return 0;
            }
            if (nums.size() == 1) {
                return nums[0];
            }
            std::vector<int> dp(nums.size(), 0);
            dp[0] = nums[0];
            dp[1] = std::max(nums[0], nums[1]);
            for (int i = 2; i < nums.size(); i++) {
                dp[i] = std::max(dp[i-1], dp[i-2]+nums[i]);
            }
            return dp[nums.size() - 1 ];
        }
};

int main()
{
    Solution solve;
    std::vector<int> num {2, 4, 1, 7, 8};
    int res = solve.rot(num);
    std::cout << res << std::endl;
}
