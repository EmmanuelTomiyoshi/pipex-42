#include <stdio.h>

int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int (*p[4]) (int x, int y);

int main(void)
{
    int result;
    int j;
    int i;

    i = 3;
    j = 9;

    p[0] = sum;
    p[1] = sub;
    p[2] = mul;
    p[3] = div;

    result = (*p[0]) (i, j);
    printf("%d\n", result);
}

int sum(int a, int b)
{
    return (a + b);
}

int sub(int a, int b)
{
    return (a - b);
}

int mul(int a, int b)
{
    return (a * b);
}

int div(int a, int b)
{
    return (a / b);
}