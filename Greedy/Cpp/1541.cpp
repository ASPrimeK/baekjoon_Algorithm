// 잃어버린 괄호
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    getline(cin, a);
    int num = 0;       // 현재 수
    int total = 0;     // 총 결과
    bool sub = false;  // -에 의한 괄호가 열린상태
    for (int i = 0; i < a.length(); i++) {
        // 숫자판단
        if ('0' <= a[i] && a[i] <= '9') {
            num = num * 10 + a[i] - '0';
        } else {  // 연산자 만남
            if (a[i] == '-') {
                if (sub) {
                    total -= num;
                    num = 0;
                } else {
                    sub = true;
                    total += num;
                    num = 0;
                }
            } else if (a[i] == '+') {
                if (sub) {
                    total -= num;
                    num = 0;
                } else {
                    total += num;
                    num = 0;
                }
            }
        }
    }
    if (sub)
        total -= num;
    else
        total += num;
    cout << total << '\n';
}