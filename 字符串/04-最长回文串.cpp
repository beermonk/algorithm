//
// Created by mengjiale on 2018/5/28.
//
#include <iostream>
#include <map>

class Solution {
public:
    int longestPalindrome(std::string str)
    {
        char charMap[128] = {0};  // 字符串哈希表
        int max_length = 0;
        int flag = 0;

        for (int i = 0; i < str.size(); i++) {
            charMap[str[i]]++;
        }
        for (int i = 0; i < 128; i++) {
            if (charMap[i] % 2 == 0) {
                max_length += charMap[i];
            }
            else {
                max_length += charMap[i] - 1;
                flag = 1;
            }
        }
        return max_length + flag;
    }
};

int main()
{
    Solution solve;
    std::string str = "helloworld";
    int res = solve.longestPalindrome(str);
    std::cout << res << std::endl;
}
