#include <stdio.h>

void myremove(int* arr, int n)
{
    int index = 2;
    int i = 0;
    for (i = 2; i < n; i++) {
        if (arr[i] != arr[index - 2]) {
            arr[index++] = arr[i];
        }
    }
}

int main(void)
{
    int arr[] = {1, 1, 1, 2, 2, 3};
    myremove(arr, 6);
    return 0;
}
