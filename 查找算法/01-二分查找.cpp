//
// Created by mengjiale on 2018/5/22.
//

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * 递归的二分查找
     */
    int binarySearch(std::vector<int> &num, int start, int end, int target)
    {
        if (start > end) {
            return -1;
        }
        int mid = start + (end - start) / 2;
        if (target == num[mid]) {
            return 1;
        }
        else if (target < num[mid]) {
            return binarySearch(num, start, mid - 1, target);
        }
        else if (target > num[mid]) {
            return binarySearch(num, mid + 1, mid, target);
        }
    }

    /**
     * 循环二分查找
     */
    int binarySearch(std::vector<int> &num, int target)
    {
        int begin = 0;
        int end = num.size() - 1;

        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (num[mid] == target) {
                return 1;
            }
            if (num[mid] > target) {
                end = mid - 1;
            }
            if (num[mid] < target) {
                begin = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    std::vector<int> num{1, 3, 8, 10, 12, 15, 20, 21, 24};
    Solution solve;
//    int res = solve.binarySearch(num, 2, 7, 9);
    int res = solve.binarySearch(num, 8);
    std::cout << res << std::endl;

}