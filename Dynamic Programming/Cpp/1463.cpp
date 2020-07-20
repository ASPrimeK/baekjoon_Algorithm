// 1 만들기

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    int count = 0;
    scanf("%d", &n);
    int *d = (int *)calloc(n + 1, sizeof(int));
    d[1] = 0;
    for (i = 2; i < n + 1; i++)
    {
        if (i == 2 || i == 3)
        {
            d[i] = 1;
            continue;
        }
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0)
        {
            if (d[i] > d[i / 2] + 1)
                d[i] = d[i / 2] + 1;
        }
        if (i % 3 == 0)
        {
            if (d[i] > d[i / 3] + 1)
                d[i] = d[i / 3] + 1;
        }
    }

    printf("%d", d[n]);
    return 0;
}