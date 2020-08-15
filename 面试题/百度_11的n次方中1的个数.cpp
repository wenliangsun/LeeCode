#include <bits/stdc++.h>

using namespace std;

/**
 * 类似杨辉三角
 */

/**
 * 字符串相加
 */
string add(string& s1, string& s2) {
    int m = s1.size(), n = s2.size();
    int carry = 0;
    string res;
    for (int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry; i--, j--) {
        int n1 = i < 0 ? 0 : s1[i] - '0';
        int n2 = j < 0 ? 0 : s2[j] - '0';
        int sum = (n1 + n2 + carry) % 10;
        carry = (n1 + n2 + carry) / 10;
        res += to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
}

int count1OfPow11(int n) {
    string num = to_string(1);
    for (int i = 0; i < n; i++) {
        string pre = to_string(0) + num; // 前面补零
        string cur = num + '0'; // 后面补零
        num = add(pre, cur); // 错位相加
    }
    int res = 0;
    for (auto c : num) // 统计1的个数
        if (c == '1') res++;
    return res;
}

int main() {
    int n;
    cin >> n;
    int res = count1OfPow11(n);
    cout << res << endl;

    return 0;
}