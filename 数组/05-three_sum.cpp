#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*问题描述：
 * 从一个无序数组中，找出满足和为指定值的三个数
 * */
class Solution {
    public:
        vector<std::vector<int>> threeSum(vector<int>& num, int target)
        {
            vector<std::vector<int>> result;
            auto last = num.end();

            if (num.size() < 3) return result; // 判断传入的参数是否合法
            std::sort(num.begin(), num.end()); // 排序vector 
            for (auto i = num.begin(); i < last - 2; i++) {  // i遍历数组，采用另外两个指针j, k调节和的大小
                if (i > num.begin() && *i==*(i-1)) continue;
                auto j = i+1;
                auto k = last - 1;
                while (j < k) {
                    if (*i + *j + *k < target) {  // 如果和小于目标值，那么需要增大j
                        ++j;
                        while (*j == *(j - 1) && j < k) ++j;
                    }
                    else if (*i + *j + *k > target) { // 如果和大于目标值，此时需要减小k
                        --k;
                        while (*k == *(k + 1) && j < k) --k;
                    }
                    else {  // 相等的情况
                        result.push_back({*i, *j, *k});
                        ++j;
                        --k;
                        while (*j == *(j - 1) && j < k) ++j;
                        while (*k == *(k + 1) && j < k) --k;
                    }
                }
            }
            return result;
        }
};

int main(void)
{
    vector<int> num {-1, 0, 2, 2, -1, -4};
    Solution solu;
    vector<std::vector<int>> res;
    res = solu.threeSum(num, 1);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << endl;
        }
    }
    
    return 0;
}
