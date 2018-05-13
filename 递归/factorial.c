#include <stdio.h>

// 求阶乘的递归方法
int factorial(int n)
{
    // 定义递归的出口
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);

}
int main()
{
    int res = factorial(5);
    printf("%d\n", res);

    return 0;
}
