#include <bits/stdc++.h>

using namespace std;

int soi(string s) {
    if (s.empty()) return 0;
    int idx = 0, res = 0, sign = 1;
    while (idx < s.size() && s[idx] == ' ') idx++;
    if (idx < s.size()) {
        if (s[idx] == '-') {
            sign = -1;
            idx++;
        } else if (s[idx] == '+')
            idx++;
    }
    while (idx < s.size()) {
        auto c = s[idx];
        if (c < '0' || c > '9') break;
        int t = sign * (c - '0');
        // 注意这个判断溢出的代码
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && t > 7))
            return INT_MAX;
        if (res < INT_MIN / 10 || (res == INT_MIN / 10 && t < -8))
            return INT_MIN;
        res = res * 10 + t;
        idx++;
    }
    return res;
}

int main() {
    string s;
    while (cin >> s) {
        cout << soi << endl;
    }
    return 0;
}