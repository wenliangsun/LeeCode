#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int strToInt(string s) {
        int idx = 0, res = 0;
        while (idx < s.size() && s[idx] == ' ') idx++;
        int sign = 1;
        if (s[idx] == '+')
            idx++;
        else if (s[idx] == '-') {
            sign = -1;
            idx++;
        }
        while (idx < s.size()) {
            if (s[idx] < '0' || s[idx] > '9') break;
            int t = sign * (s[idx] - '0');
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && t > 7))
                return INT_MAX;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && t < -8))
                return INT_MIN;
            res = res * 10 + t;
            idx++;
        }
        return res;
    }
};