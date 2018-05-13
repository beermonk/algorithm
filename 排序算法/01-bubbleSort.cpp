#include <iostream>
#include <vector>

using namespace std;


class BubbleSort {
    public:
        vector<int> bubbleSort(vector<int> &num)
        {
            for (int i = 0; i < num.size() - 1; i++)
            {
                for (int j = 0; j < num.size() - i - 1; j++)
                {
                    if (num[j] > num[j+1])
                    {
                        int temp = num[j];
                        num[j] = num[j+1];
                        num[j+1] = temp;
                    }
                }
            }
            
            return num;
        }
};

int test()
{
    vector<int> num {3, 7, 4, 6, 2, 1, 5};
    BubbleSort sort; 
    vector<int> res = sort.bubbleSort(num);
    for (auto i : res)
    {
        cout << i << "\t";
    }
    cout << endl;
    return 0;
}

int main()
{
    test();
    return 0;
}
