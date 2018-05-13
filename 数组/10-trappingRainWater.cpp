#include <iostream>
#include <vector>

using namespace std;

int test(vector<int> &num)
{
    vector<int> size;

    for (int i = 0; i < num.size(); i++) {
        // 寻找每一个柱子的左边的最大值和右边的最大值
        int maxLeft = 0;
        int maxRight = 0;
        for (int j = 0; j < i; j++) {
            if (maxLeft < num[j])
                maxLeft = num[j];
        } 
        for (int k = i + 1; k < num.size(); k++) {
            if (maxRight < num[k])
                maxRight = num[k];
        }
        if (maxLeft < maxRight && maxLeft > num[i]) {
            size.push_back(maxLeft - num[i]);
        }
        else if (maxLeft > maxRight && maxRight > num[i]) {
            size.push_back(maxRight - num[i]);
        }
    }

    int res = 0;
    for (auto i : size) {
        cout << i << "\t";
        res += i;
    }
    cout << endl;
    return res;
}

int main(void)
{
    vector<int> num {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = test(num);
    cout << res << endl;

    return 0;
}
