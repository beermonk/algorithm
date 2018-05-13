#include <stdio.h>

void move(char a, char b);

//汉诺塔问题递归
void hano(char a, char b, char c, int n)
{
    if (n > 0) {
        hano(a, c, b, n-1);
        move(a, c);
        hano(b, a, c, n-1);
    }
}
void move(char a, char b)
{
    printf("%c --> %c\n", a, b);
}

int main()
{
    char a, b, c;
    hano(a, b, c, 3);
    return 0;
}
