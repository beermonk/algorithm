//
// Created by mengjiale on 2018/5/28.
//
#include <iostream>
#include <map>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string str)
    {
        std::map<std::string, char> word_map;  // 单词到pattern的映射表
        char used[128] = {0};
        std::string word;  // 临时保存拆分出来的单词
        int pos = 0;  // 指向pattern
        str.push_back(' ');

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {  // 遇到空格说明遇到了单词
                if (pos == pattern.length()) {  // 到达pattern末尾
                    return false;
                }
                // 若单词未出现在哈希映射中
                if (word_map.find(word) == word_map.end()) {
                    if (used[pattern[pos]]) {  // 如果当前pattern字符已经使用
                        return false;
                    }
                    word_map[word] = pattern[pos];
                    used[pattern[pos]] = 1;
                }
                else {
                    if (word_map[word] != pattern[pos]) {
                        return false;
                    }
                }
                word = "";
                pos++;
            }
            else {
                word +=str[i];
            }
        }
        if (pos != pattern.length()) {
            return false;
        }
        return true;
    }
};

int main()
{
    std::string pattern = "abba";
    std::string str = "dog boy boy dog cat";
    Solution solve;
    bool res = solve.wordPattern(pattern, str);
    std::cout << res << std::endl;
}
