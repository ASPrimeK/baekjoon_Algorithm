#include <stdio.h>

typedef struct _pair
{
    bool check;
    int zero;
    int one;
} pair;

pair c[41];

pair fib(int x)
{
    if (c[x].check == true)
    {
        return c[x];
    }
    if (x == 0)
    {
        c[0].check = true;
        c[0].zero = 1;
        c[0].one = 0;
        return c[0];
    }
    if (x == 1)
    {
        c[1].check = true;
        c[1].zero = 0;
        c[1].one = 1;
        return c[1];
    }
    pair p1 = fib(x - 1);
    pair p2 = fib(x - 2);
    c[x].check = true;
    c[x].zero = p1.zero + p2.zero;
    c[x].one = p1.one + p2.one;
    return c[x];
}

int main()
{
    for (int i = 0; i < 41; i++)
        c[i].check = false;

    int num;
    scanf("%d", &num);
    int x;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &x);
        pair a = fib(x);
        printf("%d %d\n", a.zero, a.one);
    }
}