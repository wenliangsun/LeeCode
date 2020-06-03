#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 位运算
     */
    int add(int a, int b) {
        int res = 0, carry = 0;
        res = a ^ b;
        carry = (unsigned int)(a & b) << 1;
        int n1 = res, n2 = carry;
        while (n2) {
            res = n1 ^ n2;
            carry = (unsigned int)(n1 & n2) << 1;
            n1 = res, n2 = carry;
        }
        return res;
    }
};