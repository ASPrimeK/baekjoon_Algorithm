// ATM
#include <iostream>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int sum = 0;
    int n, result = 0;
    std::cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    qsort(a, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        result += sum;
    }
    std::cout << result;
    delete[] a;
    return 0;
}