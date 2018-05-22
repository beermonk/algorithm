//
// Created by mengjiale on 2018/5/15.
//

#include <iostream>
#include <queue>

class Solution {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int> > small_heap;
    std::priority_queue<int> big_heap;
public:
    void push(int x)
    {
        if (big_heap.empty()) {
            big_heap.push(x);
            return;
        }
        if (big_heap.size() == small_heap.size()) {
            if (x < big_heap.top()) {
                big_heap.push(x);
            }
            else {
                small_heap.push(x);
            }
        }
        else if (big_heap.size() > small_heap.size()) {
            if (x > big_heap.top()) {
                small_heap.push(x);
            }
            else {
                small_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(x);
            }
        }
        else if (big_heap.size() < small_heap.size()) {
            if (x < small_heap.top()) {
                big_heap.push(x);
            }
            else {
                big_heap.push(small_heap.top());
                small_heap.pop();
                small_heap.push(x);
            }
        }

    }

    double findMedian()
    {
        // 如果big_heap.size()和small_heap.size()相等，中位数为两者堆顶值的平均值
        double mid = 0;
        if (big_heap.size() == small_heap.size()) {
            mid = (big_heap.top() + small_heap.top()) / 2.0;
        }
        else if (big_heap.size() < small_heap.size()) {
            mid = small_heap.top();
        }
        else
            mid = big_heap.top();

        return mid;
    }
};

int main()
{
    Solution solv;
    std::vector<int> num{3, 2, 8, 7, 4, 9};
    for (int i = 0; i < num.size(); i++) {
        solv.push(num[i]);
    }
    double res = solv.findMedian();
    std::cout << res << std::endl;
}