#include <iostream>
#include <vector>

using namespace std;

int factorial(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

vector<int> KthPermutation(int n,int k)
{

    vector<int> vec;
    vector<int> res;

    for (int i = 0; i < n; i++)
        vec.push_back(i+1);
    int base = factorial(n-1);
    k--;
    for (int i = 0; i < n-1; i++) {
        int divieRes = k/base;
        k = k % base;
        // 得到数值
        auto num = next(vec.begin(),divieRes);  // next方法，返回第一个参数后第二个参数距离的数值
        res.push_back(*num);
        vec.erase(num);
        base /= (n-i-1);
    }
    res.push_back(vec[0]);
    return res;
}
void test()
{
    vector<int> res = KthPermutation(5, 96);
    for (auto i : res) 
        cout << i << endl;
}
int main(void)
{
    test();
    return 0;
}
