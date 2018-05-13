#include <stdio.h>

//确定递归模型
// f(1) = 1;
// f(n) = n * f(n-1)  n >= 2;

int f(int n)
{
    if (n == 1)
        return 1;
    else
        return n * f(n-1);
}

void swap(char*s , int i, int j)
{
    // 交换s中i和j位置的元素
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
void Permutation(char* s, int length, int head)
{
    if (head == length - 1) {
        printf("%s\n", s);
    } 
    else {
        for (int i = head; i < length - 1; i++) {
            swap(s, i, head);    
            Permutation(s, length - 1, head + 1);
            swap(s, i, head);    
        }
    }
}

int main()
{
    char* s = "hel";
    int res = f(3);
    printf("%d\n", res);
    Permutation(s, 3, 0);
    return 0;
}

