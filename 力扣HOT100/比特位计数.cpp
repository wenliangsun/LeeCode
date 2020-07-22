#include <bits/stdc++.h>

using namespace std;

/**
 * 题目338：比特位计数
 */

class Solution {
   public:
    /**
     * 时间复杂度：O(nk)
     */
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i = 0; i <= num; i++) {
            int cnt = 0;
            int n = i;
            while (n) {  // 统计每一个数字的二进制中1的个数
                n = n & (n - 1);
                cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }

    /**
     * x可以看成是x’左移一位再加上新添进来的一位的结果
     * 时间复杂度：O(n)
     */
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for (int i = 1; i <= num; i++) res[i] = res[i >> 1] + (i & 1);
        return res;
    }
};