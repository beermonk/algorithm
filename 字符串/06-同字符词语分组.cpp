//
// Created by mengjiale on 2018/5/28.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagram(std::vector<std::string> &strs)
    {
        std::map<std::string, std::vector<std::string>> mymap;  //  临时的map
        std::vector<std::vector<std::string>> res;
        // 遍历字符串向量
        for (auto i : strs) {
            std::string temp = i;
            std::sort(temp.begin(), temp.end());
            if (mymap.find(temp) == mymap.end()) {  // 如果在map中
                std::vector<std::string> item;
                mymap[temp] = item;
            }
            mymap[temp].push_back(i);
        }
        // 将hash表中的数据，放入res结果中
        for (auto i: mymap) {
            res.push_back(i.second);
        }

        return res;
    }
};

int main()
{
    Solution solve;

    std::vector<std::string> strs{"eat", "tea", "ate", "dog", "ogd", "odg", "apple", "happy"};
    std::vector<std::vector<std::string>> res = solve.groupAnagram(strs);
    for (auto i : res) {
        for (auto j : i) {
            std::cout << j << std::endl;
        }
    }
}
