#include <iostream>
#include <vector>

using namespace std;

int test(vector<int> &num)
{
    int peakIndex = 0;

    // 寻找最大值的下标
    for (int i = 0; i < num.size(); i++) {
        if (num[i] > num[peakIndex]) peakIndex = i;
    }

    int water = 0;
    for (int i = 0, leftPeak = 0; i < peakIndex; i++) { // 处理最高值的左边
        if (num[i] > leftPeak) leftPeak = num[i];
        else water += leftPeak - num[i];
    }    
    for (int j = num.size(), rightPeak = 0; j > peakIndex; j--) {  // 处理最高值的右边
        if (num[j] > rightPeak) rightPeak = num[j];
        else water += rightPeak - num[j];
    }

    return water;
}

int main(void)
{
    vector<int> num {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = test(num);
    cout << res << endl;

    return 0;
}
