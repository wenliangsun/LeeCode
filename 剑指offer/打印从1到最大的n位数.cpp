#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 正常打印
     */
    vector<int> printNumbers(int n) {
        int mx = pow(10, n);
        vector<int> res;
        for (int i = 1; i < mx; i++) res.push_back(i);
        return res;
    }
};