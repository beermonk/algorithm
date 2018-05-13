#include <iostream>
#include <vector>

using namespace std;
vector<int> shellSort(vector<int>& num)
{

    int d = num.size();
    while (true) {
        d = d / 2;
        for (int x = 0; x < d; x++) {  // 遍历每一个分组
            for (int i = x + d; i < num.size(); i = i + d) {  // 对分组中的数据进行排序
                int temp = a[i];
                int j;
                for (j = i - d; j >= 0 && num[j] > temp; j = j - d) {
                    a[j + d] = num[j];
                }
                num[j + d] = temp;
            }
        }
        if (d == 1) {
            break;
        }
    }

    return num;
}
