//
// Created by mengjiale on 2018/5/23.
//

#include <iostream>
#include <vector>

class Solution {
private:
    int leftBoundry(std::vector<int> &num, int target)
    {
        int begin = 0;
        int end = num.size();

        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (target == num[mid]) {
                if (mid == 0 || num[mid - 1] < target) {
                    return mid;
                }
                end = mid - 1;
            }
            else if (target < num[mid]) {
                end = mid - 1;
            }
            else if (target > num[mid]) {
                begin = mid + 1;
            }
        }
        return -1;
    }

    int rightBoundry(std::vector<int> &num, int target)
    {
        int begin = 0;
        int end = num.size();

        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (target == num[mid]) {
                if (mid == num.size() - 1 || num[mid + 1] > target) {
                    return mid;
                }
                begin = mid + 1;
            }
            else if (target < num[mid]) {
                end = mid - 1;
            }
            else if (target > num[mid]) {
                begin = mid + 1;
            }
        }
        return -1;
    }

public:
    void findBoundry(std::vector<int> &num, int target)
    {
        int left = leftBoundry(num, target);
        int right = rightBoundry(num, target);
        std:: cout << "left :   " << left << std::endl;
        std:: cout << "right:   " << right << std::endl;
    }
};

int main()
{
    std::vector<int> num{5, 7, 7, 8, 8, 8, 8, 10};
    Solution solve;
    solve.findBoundry(num, 12);

}