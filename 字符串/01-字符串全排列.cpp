#include <iostream>
#include <cstring>

using namespace std;

void swap(char* s, int a, int b)
{
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

bool isSwap(char* s, int a, int b)
{
    for (; a < b; a++) {
        if (s[a] == s[b]) {
            return false;
        }
    }
    return true;
}

void test(char* str, int from, int to)
{
    if (from == to) {
        cout << str << endl;
    }
    // 以str中的n个字符作为开头, 如果有重复的字符，第一个出现的该字符进行交换，之后在出现的该字符不在需要进行交换
    for (int i = from; i < to; i++) {
        if (isSwap(str, from , i)) {
            swap(str, i, from);  // 实现以n个字符分别作为开头
            test(str, from + 1, to); // 去掉首字符之后的字符串递归调用
            swap(str, i, from);  // 恢复为原始的字符串
        }
    }
}

int main()
{
    char str[] = "aab";
    test(str, 0, 3);
    return 0;
}
