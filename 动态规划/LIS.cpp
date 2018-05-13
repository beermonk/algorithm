#include <iostream>

using namespace std;

int lis(int *arr, int n) {
    int *d = new int[n];
    int len = 1;
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] <= arr[i] && d[j] + 1 > d[i])
                d[i] = d[j] + 1;
            if (d[i] > len)
                len = d[i];
        }
    }
    delete[] d;
    return len;
}

int main(void) {
    int arr[] = {2, 3, 1, 8, 5, 6};
    int n = lis(arr, sizeof(arr) / sizeof(int));
    cout << n << endl;
    return 0;
}
