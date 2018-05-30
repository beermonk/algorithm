//
// Created by Monk on 2018/5/28.
//
#include <iostream>
#include <map>

class Solution {
public:
    int lengthOfLongestSubStirng(std::string str)
    {
        int begin = 0;
        int result = 0;
        std::string word = "";
        int char_map[128] = {0};

        for (int i = 0; i < str.size(); i++) {
            char_map[str[i]]++;
            if (char_map[str[i]] == 1) {  // word中没有出现过该字符
                word += str[i];
                if (result < word.length()) {
                    result = word.length();
                }
            }
            else {  // 如果在word中出现过
                while (begin < i && char_map[str[i]] > 1) {
                    char_map[str[begin]]--;
                    begin++;
                }
                word = "";
                for (int j = begin; j <= i; j++) {
                    word += str[j];
                }
            }

        }
        return result;
    }
};

int main()
{
    std::string str = "abceacdefbcdac";
    Solution solve;
    int result = solve.lengthOfLongestSubStirng(str);
    std::cout << result << std::endl;
}
