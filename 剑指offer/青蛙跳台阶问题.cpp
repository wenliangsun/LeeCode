#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    // 备忘录
    int numWays(int n) {
        if (n == 0 || n == 1) return 1;
        if (n == 2) return 2;
        int res = 0, a = 1, b = 2;
        for (int i = 3; i <= n; i++) {
            res = a + b;
            if (res > 1e9 + 7) res -= (1e9 + 7);
            a = b;
            b = res;
        }
        return res > 1e9 + 7 ? res - (1e9 + 7) : res;
    }
};