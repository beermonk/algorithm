//
// Created by mengjiale on 2018/5/16.
//

#include <iostream>
#include <queue>
#include <string>


class Solution {
public:
    /**
     * 一个字符串，里面全是数字，删除其中的k个数字，使得剩下的数字对应的数最小
     * @param src
     * @param k
     * @return
     */
    std::string removeKdigits(std::string src, int k)
    {
        std::vector<int> s;
        std::string res = "";

        for (int i = 0; i < src.length(); i++) {
            int number = src[i] - '0';
            while (s.size() != 0 && s[s.size() - 1] > number && k > 0) {
                s.pop_back();
                k--;
            }
            if (number != 0 || s.size() != 0) {
                s.push_back(number);
            }
        }
        while (s.size() != 0 && k > 0) {
            s.pop_back();
            k--;
        }
        for (int i = 0; i < s.size(); i++) {
            res.append(1, '0' + s[i]);
        }
        if (res == "") {
            res = '0';
        }
        return res;
    }
};

int main()
{
    Solution solve;
    std::string s = "1432219";
    std::string res = solve.removeKdigits(s, 3);
    std::cout << res << std::endl;
}
