#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * 找出字符串中第一个只出现一次的字符
 */

int main() {
    string s;
    while (cin >> s) {
        unordered_map<char, int> m;
        for (auto c : s) {
            m[c]++;
        }
        bool f = true;
        for (auto c : s) {
            if (m[c] == 1) {
                cout << c << endl;
                f = false;
                break;
            }
        }
        if (f) cout << -1 << endl;
    }
    return 0;
}