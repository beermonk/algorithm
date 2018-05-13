#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &num, int l, int r)
{
    if (l >= r) {
        return;
    }

    int i = l;
    int j = r;
    int pivot = num[i];

    while (i < j) {
        while (num[j] >= pivot && i < j) {
            j--;
        }
        // 将num[j]放在i的位置
        if (i < j)
            num[i++] = num[j];
        while (num[i] < pivot && i < j) {
            i++;
        }
        // 将num[i]放在j的位置
        if (i < j)
            num[j--] = num[i];
    }
    // 当i和j相等时,将基准数放在该位置
    num[i] = pivot;
    quickSort(num, l, i-1);
    quickSort(num, i+1, r);
}

int main()
{
    vector<int> num {1, 4, 3, 2, 5};
    quickSort(num, 0, 5);
    for (auto i : num)
        cout << i << endl;
    return 0;
}
