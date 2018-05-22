//
// Created by mengjiale on 2018/5/15.
//

#include <iostream>
#include <queue>

class Solution {
public:
    /**
     * 求一个未排序数组中的第K大的数
     * @param num
     * @param k
     * @return
     */
    int findKthLargest(std::vector<int> &num, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> small_heap;  // 创建一个最小堆
        for (int i = 0; i < num.size(); i++) {
            if (small_heap.size() < k) {
                small_heap.push(num[i]);
            }
            else if (small_heap.top() < num[i]) {
                small_heap.pop();
                small_heap.push(num[i]);
            }
        }

        return small_heap.top();
    }
};

int main()
{
    Solution solve;
    std::vector<int> num{3, 2, 1, 4, 5, 7};
    int res = solve.findKthLargest(num, 2);
    std::cout << res << std::endl;
}
