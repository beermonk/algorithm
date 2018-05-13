#include <iostream>
#include <string>

using namespace std;

/*字符串翻转*/
void strReverse(string &str, int idxFrom, int idxTo)
{
    while (idxFrom < idxTo) {
        char tmp = str[idxFrom];
        str[idxFrom++] = str[idxTo];
        str[idxTo--] = tmp;
    } 
}

void strLeftMoving(string &str, int n, int k)  // 字符串str循环左移n位
{
    k = k % n;
    strReverse(str, 0, k - 1); // 转置A
    strReverse(str, k, n -1); // 转置B
    strReverse(str, 0, n - 1);
}

int main(void)
{
    string s = "beautiful";
    strLeftMoving(s, 9, 3);
    cout << s << endl;
    return 0;
}
