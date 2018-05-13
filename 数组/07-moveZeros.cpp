#include <iostream>
#include <vector>

using namespace std;


vector<int> moveZeros(vector<int>& num)
{
    int index = 0;  // index代表慢指针
    while(num[index]) {  // index先找到数组中第一个为零的元素
        index++;
    }
    for (int i = 0; i < num.size(); i++) {  // i代表快指针
        if (num[i] != 0 && i >= index) {
            // 交换index指向的值和i指向的值
            int temp = num[i];
            num[i] = num[index];
            num[index] = temp;
            index++;
        }
    }

    return num;
}

void test()
{
    vector<int>  num {1, 1, 0, 3, 0};
    vector<int> res = moveZeros(num);
    for (auto i : res)
        cout << i << "\t";
    cout << endl;
}

int main()
{
    test();
    return 0;
}
