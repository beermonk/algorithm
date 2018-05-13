#include <iostream>
#include <vector>

using namespace std;

class SelectSort {
    public:
        vector<int> selectSort(vector<int>& num)
        {
            for (int i = 0; i < num.size() - 1 ; i++) {  // i记录数组中有序部分的下标，j记录无序部分的下标
                int maxIndex = i;
                int maxValue = num[maxIndex];
                for (int j = i + 1; j < num.size(); j++) {
                    if (num[j] < maxValue) {
                        maxIndex = j;
                        maxValue = num[maxIndex];
                    }
                }
                int temp = num[i];
                num[i] = maxValue;
                num[maxIndex] = temp;
            }
            return num;
        }
};

void test()
{
    vector<int> num {3, 7, 4, 6, 2, 1, 5, 8};
    vector<int> res;
    SelectSort sort;
    res = sort.selectSort(num);
    for (auto i : res) {
        cout << i << "\t";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}
