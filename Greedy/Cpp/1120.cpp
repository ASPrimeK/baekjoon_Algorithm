// 문자열
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a.length() < b.length()) swap(a, b);
    int la = a.length();
    int lb = b.length();
    int min = 1000000;
    for (int i = 0; i <= la - lb; i++) {
        int wrong = 0;
        for (int j = i; j < i + lb; j++) {
            if (a[j] != b[j - i]) wrong++;
        }
        if (wrong < min) min = wrong;
    }
    cout << min << '\n';
}