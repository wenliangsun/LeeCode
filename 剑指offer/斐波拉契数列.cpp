#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    // 备忘录 , 还可以递归 就是常规操作了
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 0, b = 1;
        int res = 0;
        for (int i = 2; i <= n; i++) {
            res = a + b;
            if (res > 1e9 + 7) res -= (1e9 + 7);
            a = b;
            b = res;
        }
        return res > 1e9 + 7 ? res - (1e9 + 7) : res;
    }
};