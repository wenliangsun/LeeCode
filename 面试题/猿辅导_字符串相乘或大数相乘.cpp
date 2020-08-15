#include <bits/stdc++.h>

using namespace std;

/**
 * 字符串相乘或大数相乘
 * 考察点：大数相乘和字符串相加
 */

class Solution {
   public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res;
        for (int i = num2.size() - 1; i >= 0; i--) {
            string t;
            int carry = 0;
            for (int j = i + 1; j < num2.size(); j++) t += '0';
            int n2 = num2[i] - '0';
            for (int j = num1.size() - 1; j >= 0 || carry; j--) {
                int n1 = j < 0 ? 0 : num1[j] - '0';
                int n = n1 * n2 + carry;
                t += to_string(n % 10);
                carry = n / 10;
            }
            reverse(t.begin(), t.end());
            res = add(res, t);
        }
        return res;
    }

    string add(string& s1, string& s2) {
        string res;
        int carry = 0;
        for (int i = s1.size() - 1, j = s2.size() - 1; i >= 0 || j >= 0 || carry; i--, j--) {
            int n1 = i < 0 ? 0 : s1[i] - '0';
            int n2 = j < 0 ? 0 : s2[j] - '0';
            int sum = n1 + n2 + carry;
            res += to_string(sum % 10);
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s = Solution();
    string s1 = "123";
    string s2 = "3";
    string res = s.multiply(s1, s2);
    cout << res << endl;
    return 0;
}