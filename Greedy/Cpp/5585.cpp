// 거스름돈
#include <iostream>
using namespace std;
int main() {
    int input;
    cin >> input;
    input = 1000 - input;
    int count = 0;
    count += input / 500;
    input %= 500;
    count += input / 100;
    input %= 100;
    count += input / 50;
    input %= 50;
    count += input / 10;
    input %= 10;
    count += input / 5;
    input %= 5;
    count += input / 1;
    input %= 1;
    cout << count;
}