#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 双指针
     */
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int sum = 0;
        for (int i = 1; i <= (target + 1) / 2; i++) {  // 枚举起点
            for (int j = i;; j++) {                    // 枚举终点
                sum += j;                              // 累计和
                if (sum > target) {
                    sum = 0;
                    break;
                } else if (sum == target) {
                    vector<int> t;
                    for (int k = i; k <= j; k++) t.push_back(k);
                    res.push_back(t);
                    sum = 0;
                    break;
                }
            }
        }
        return res;
    }
};