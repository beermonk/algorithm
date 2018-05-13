#include <iostream>
#include <vector>

using namespace std;

void test()
{
    vector<vector<int>> res;
    vector<vector<int>> num {
        {1, 2},
        {3, 4}
    };
    int n = num.size();
    for (int i = 0; i < n; i++) {  // 沿着对角线旋转
        for (int j = 0; j < n - i; j++) {
            swap(num[i][j], num[n-1-j][n-1-i]); // 对角矩阵的坐标关系
        } 
    }
}

int main()
{
    test();
    return 0;
}
