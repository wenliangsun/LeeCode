#include <bits/stdc++.h>

using namespace std;

/**
 * 题目605：种花问题
 */

class Solution {
   public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int idx = 0, cnt = 0;
        while (idx < f.size()) {
            // 当前位置可以种花的条件
            if (f[idx] == 0 && (idx == 0 || f[idx - 1] == 0) &&
                (idx == f.size() - 1 || f[idx + 1] == 0)) {
                f[idx] = 1;
                cnt++;
            }
            idx++;
        }
        return n <= cnt;
    }
};