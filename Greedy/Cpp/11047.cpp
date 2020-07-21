// 동전 0
#include <iostream>
using namespace std;

int main()
{
    int n, k, result = 0;
    cin >> n >> k;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i >= 0; i--)
    {
        result += k / a[i];
        k = k % a[i];
    }

    cout << result;
    delete[] a;
}