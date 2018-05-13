#include <iostream>

using namespace std;

void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;  
            if(i < j) 
                s[i++] = s[j];

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;  
            if(i < j) 
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用 
        quick_sort(s, i + 1, r);
    }
}

int main(void)
{
    // int arr[] = {2, 3, 1, 4, 7, 8, 5};
    int arr[] = {3, 2, 1, 5, 7};
    int n = sizeof(arr)/sizeof(int);
    quick_sort(arr, 0, n);
    int i = 0;
    for (i=0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    
    return 0;
}
