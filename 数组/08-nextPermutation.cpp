#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nextPermutation(vector<int>& num)
{
    int i = 0;
    int j = 0;
    // 判断num[i]的右边有没有比num[i]大的数, 就是寻找连续递增序列
    for (i = num.size() - 1; i > 0 && num[i] < num[i-1]; i--);
    // 得到的i之后的数组为连续递增序列
    if (i == 0) { // 此时整个数组为从右到左连续递增
        std::sort(num.begin(), num.end());
        return num;
    }
    for (j = i; j < num.size() && num[j] > num[i-1]; j++);
    // 此时得到的j为最小值
    int tem = num[i-1];
    num[i-1] = num[j-1];
    num[j-1] = tem;

    return num;
}
void test()
{
    vector<int> num {1, 2, 3};
    vector<int> res;
    res = nextPermutation(num);
    for (auto i : res)
        cout << i << "\t";

    cout << endl;
}

int main(void)
{
    test();
    return 0;
}
