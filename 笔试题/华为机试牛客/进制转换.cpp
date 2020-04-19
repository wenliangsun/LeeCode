#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。（多组同时输入 ）
 */

typedef long long LL;

int main() {
    string s;

    while (getline(cin, s)) {
        if (s.size() <= 0) break;
        LL num = 0;
        for (int i = 2; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 16 + s[i] - '0';
            } else {
                num = num * 16 + s[i] - 'A' + 10;
            }
        }
        cout << num << endl;
    }
}