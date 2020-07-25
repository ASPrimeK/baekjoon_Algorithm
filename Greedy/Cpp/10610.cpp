// 30
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int sum = 0;
    bool mul10 = false;
    string input;
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '0') mul10 = true;
        sum += input[i] - '0';
    }
    if (mul10 == false || sum % 3 != 0)
        cout << -1;
    else {
        sort(input.begin(), input.end(), greater<char>());
        cout << input;
    }
}