#include <bits/stdc++.h>

using namespace std;

/**
 * 题目168：Excel表列号
 */

class Solution {
   public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            n = n - 1;
            int t = n % 26;
            res += (t + 'A');
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};