#include <iostream>
#include <string>

using namespace std;

/**
 * 给定一个字符串，请你将字符串重新编码，将连续的字符替换成“连续出现的个数+字符”。
 * 比如字符串AAAABCCDAA会被编码成4A1B2C1D2A。
 */

int main() {
    string a;
    string b;
    cin >> a;
    int i = 0;
    int n = 1;
    while (i < a.size()) {
        if (a[i + 1] == a[i]) {
            n++;
        } else {
            cout << n << a[i];
            n = 1;
        }
        i++;
    }
}