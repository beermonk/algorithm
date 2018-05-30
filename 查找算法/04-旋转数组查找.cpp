//
// Created by mengjiale on 2018/5/24.
//
#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int> &num, int target)
    {
        int begin = 0;
        int end = num.size();
        int mid = 0;

        while (begin <= end) {
            mid = (begin + end) / 2;
            if (num[mid] == target) {
                return mid;
            }
            if (num[mid] > target) {
                if (num[mid] > num[begin]) {
                    if (target >= num[begin]) {
                        end = mid - 1;
                    }
                    else {
                        begin = mid + 1;
                    }
                }
                else if (num[begin] > num[mid]) {
                    end = mid - 1;
                }
            }
            if (num[mid] < target) {
                if (num[begin] < num[mid]) {
                    begin = mid + 1;
                }
                else if (num[begin] > num[mid]) {
                    if (target >= num[begin]) {
                        end = mid - 1;
                    }
                    else {
                        begin = mid + 1;
                    }
                }
                else if (num[begin] == num[mid]) {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    std::vector<int> num{5, 7, 12, 15, 20, 1, 3};
    Solution solve;
    int res = solve.search(num, 3);
    std::cout << res << std::endl;
}

