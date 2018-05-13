#include <iostream>
#include <vector>

using namespace std;

class InsertSort {
    public:
        vector<int> insertSort(vector<int>& num)
        {
            for (int i = 1; i < num.size(); i++) {  
                // i 指向数组中的无序部分从左->右移动，j 指向数组的有序部分从右->左移动
                for (int j = i; j > 0; j--) {
                    if (num[j-1] > num[j]) {
                        int temp = num[j];
                        num[j] = num[j-1];
                        num[j-1] = temp;
                    }
                    else {
                        break;
                    }
                }
            }
            return num;
        }
};

void test()
{
    InsertSort sort;
    vector<int> num {3, 7, 6, 4, 2, 1, 11, 2, 5};
    vector<int> res = sort.insertSort(num);
    for (auto i : res)
    {
        cout << i << endl;
    }
}

int main()
{
    test();
}
