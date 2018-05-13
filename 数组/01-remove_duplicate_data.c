#include <stdio.h>

// 去除已排序数组中的重复数据
// 方法一
void myremove(int* arr, int n)
{
    int i = 0;
    int temp = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] != temp)
            temp = arr[i];
        else {
            for (int j = i; j < n; j++) {
                arr[j] = arr[j+1];
            }
        }

    }

    for (i = 0; i < 5; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
// 方法二
int* myremove2(int* arr, int n)
{
    int index = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[index-1]) {
            arr[index++] = arr[i];
        }
    }
    return arr;
}

int delete(int* arr, int n)
{
    int index = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[index-1]) {
            arr[index++] = arr[i];
        }
    }
}

int main(void)
{
    int arr[] = {1, 1, 1, 2, 2, 3, 4, 5};
    int *new = NULL;
    new = myremove2(arr, 8);
    for (int i = 0; i < 5; i++) {
        printf("%d\t", new[i]);
    }
    printf("\n");
    return 0;

}

