// 1, 2, 3 더하기
#include <stdio.h>

int main()
{
    int i, n, x;
    int d[11];
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (i = 4; i < 11; i++)
    {
        d[i] = d[i - 3] + d[i - 2] + d[i - 1];
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        printf("%d\n", d[x]);
    }
    return 0;
}