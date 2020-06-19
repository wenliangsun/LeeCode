#include <bits/stdc++.h>

using namespace std;

/**
 * 题目495：提莫攻击
 */
class Solution {
   public:
    /**
     * 计算两次攻击的时间差，如果大于持续时间，则中毒为持续时间，如果小于持续时间，因为中毒不能叠加，中毒时间为时间差
     */
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (!timeSeries.size()) return 0;
        int res = 0;
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            res += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        res += duration;
        return res;
    }
};