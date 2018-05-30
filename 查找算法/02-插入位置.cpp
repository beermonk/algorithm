//
// Created by mengjiale on 2018/5/23.
//
#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsertPosition(std::vector<int> &num, int target)
    {
        int index = -1;  // 要返回的数组下标
        int begin = 0;
        int end = num.size() - 1;
        int mid = 0;

        while (index == -1) {
            mid = (begin + end) / 2;
            if (target == num[mid]) {
                index = mid;
            }
            else if (target < num[mid]) {
                if (mid == 0 || target > num[mid-1]) {
                    index = mid;
                }
                end = mid - 1;
            }
            else if (target > num[mid]) {
                if (mid == num.size() - 1 || target < num[mid + 1]) {
                    index = mid + 1;
                }
                begin = mid + 1;
            }
        }
        return index;
    }
};

int main()
{
    std::vector<int> num{1, 3, 8, 10, 12, 15, 20, 21, 24};
    Solution solve;
    int res = solve.searchInsertPosition(num, 9);
    std::cout << res << std::endl;
}
