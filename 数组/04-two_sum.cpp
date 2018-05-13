#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        vector<int> twoSum(vector<int> &num, int target)
        {
            unordered_map<int, int> my_map;
            vector<int> result;  // 定义一个vector来保存要返回的数组的下标

            // 使用unordered_map 将vector中的元素进行保存, 键为元素的值，值为元素的下标值
            for (int i = 0; i < num.size(); i++) {
                my_map[num[i]] = i;
            }

            for (int i = 0; i < num.size(); i++) {
                auto iter = my_map.find(target - num[i]);
                // iter->first为键，iter->second 为值
                if (iter != my_map.end() && iter->second > i) {  // 如果找到了
                    result.push_back(i+1);  // push_back向vector的末尾追加元素
                    result.push_back(iter->second + 1);
                }
            }
            return result;
        }
};

int test()
{
    Solution solu;

    std::vector<int> num {1, 3, 2, 4, 5};
    vector<int> res = solu.twoSum(num, 5);
    for (auto i : res) {
        std::cout << i << "\t" << num[i-1] << std::endl;
    }

    return 0;
}

int main()
{
    test();
}
