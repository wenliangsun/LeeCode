#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 快速幂模板！！！
     */
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double res = 1, t = x;
        long long tn = n;
        long long absn = tn > 0 ? tn : -tn;
        while (absn) {
            if (absn & 1) res = res * t;
            t = t * t;
            absn >>= 1;
        }
        return n > 0 ? res : 1 / res;
    }
};