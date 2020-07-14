#include <bits/stdc++.h>

using namespace std;

/**
 * 比特位计数
 */

class Solution {
   public:
    // 时间复杂度：O(n) 
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for (int i = 1; i <= num; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
    // 朴素版本 时间复杂度O(nk)
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i = 0; i <= num; i++) {
            int n = i, cnt = 0;
            while (n) {
                cnt++;
                n = n & (n - 1);
            }
            res.push_back(cnt);
        }
        return res;
    }
};