#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        /*方法1：直接对数组进行排序，然后再求解，此时的时间复杂度为nlogn*/
        int longestConsecutive(std::vector<int> &num) {
            int count = 0; // 用来对可能出现的连续数组中的元素个数进行计数
            int previous = 0;  // 用来记录当前位置的前一个位置的值
            int maxLen = 0;  // 用来统计最大的长度

            std::sort(num.begin(), num.end());
            for (auto iter = num.begin(); iter != num.end(); iter++) {
                if (iter == num.begin()) {  // 由于第一个数此时没有前一个数,为此对第一个数直接进行计数器+1
                    count++;
                }
                if (*iter == previous) { // 如果数组中有重复的数
                    continue;
                }
                if (*iter - 1 == previous) { // 如果数组中当前值与前一个值相差1计数器就要进行+1
                    count++;
                } else {  // 如果当前值与前一个值不相差1说明不连续，此时就要对计数器进行归1，同时更新最长连续数组的长度
                    if (maxLen < count) {
                        maxLen = count;
                    }
                    count = 1;
                }
                previous = *iter;
            }
            // 有一个连续数组到最后一个元素的情况,此时count会大于任意一个maxLen
            if (count > maxLen) {
                maxLen = count;
            }
            return maxLen;
        }
};

class Solution2 {
    public:
        int longetstConsecutive(vector<int> &num)
        {
            unordered_set<int> my_set;
            for (auto i: num) my_set.insert(i); // 构建hash表将数据存入hash中

            int longest = 0;
            for (auto i: num) {
                int length = 1;
                // my_set.find() 如果找到，就会返回一个和查找的值相等的迭代器，如果找不到，就返回my_set.end()的返回值；
                // 在下面的条件中，如果找不到就无法执行for循环中的代码
                for (int j = i - 1; my_set.find(j) != my_set.end(); --j) {
                    my_set.erase(j);
                    ++length;
                }
                for (int j = i+1; my_set.find(j) != my_set.end(); ++j) {
                    my_set.erase(j);
                    ++length;
                }
                if (longest < length) {
                    longest = length;
                }
            }

            return longest;
        }
};


int main() 
{
    //    Solution solu;
    int a[] = {1,3,5,4,7};
    vector<int> num(a, a + 8);
    //    int res = solu.longestConsecutive(num);
    //    cout << res << endl;
    Solution2 solution;
    int res = solution.longetstConsecutive(num);
    cout << res << endl;
    return 0;
}
