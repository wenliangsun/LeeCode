#include <bits/stdc++.h>

using namespace std;

string add(string s1, string s2) {
    string res = "";
    int carry = 0;
    // 注意这儿代码的写法 技巧
    for (int i = s1.size() - 1, j = s2.size() - 1; i >= 0 || j >= 0 || carry;
         i--, j--) {
        int n1 = i < 0 ? 0 : s1[i] - '0';
        int n2 = j < 0 ? 0 : s2[j] - '0';
        int sum = (n1 + n2 + carry) % 10;
        carry = (n1 + n2 + carry) / 10;
        res = to_string(sum) + res;
    }
    return res;
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        string res = "0";
        for (int i = s2.size() - 1; i >= 0; i--) {
            string t = "";
            int carry = 0;
            // 补零操作
            for (int j = s2.size() - 1; j > i; j--) {
                t += '0';
            }
            int n2 = s2[i] - '0';
            // 相乘操作
            for (int j = s1.size() - 1; j >= 0 || carry != 0; j--) {
                int n1 = j < 0 ? 0 : s1[j] - '0';
                int mul = (n1 * n2 + carry);
                t = to_string(mul % 10) + t;
                carry = mul / 10;
            }
            res = add(t, res);
        }
        cout << res << endl;
    }
    return 0;
}