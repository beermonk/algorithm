#include <stdio.h>

// 求解数组中的最小值
int f(int* arr, int i)
{
    int min = 0;

    if (i == 0)
        return arr[0];
    else
    {
        min = f(arr, i - 1);
        if (min > arr[i])
            return arr[i];
        else
            return min;
    }
}
int main()
{
    int arr[5] = {3, 4, 8, 6, 2};
    int res = f(arr, 4);
    printf("%d\n", res);
    return 0;
}
