#include <bits/stdc++.h>

using namespace std;

/**
 * 在D天内送达包裹的能力 力扣1011
 */

class Solution {
   public:
    /**
     * 二分法 查找
     */
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 0, r = 0;
        for (auto w : weights) {
            l = max(l, w);
            r += w;
        }
        while (l < r) {
            int mid = (l + r) >> 1;
            if (canfinished(weights, mid, D)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    bool canfinished(vector<int>& weights, int mid, int d) {
        int cnt = 0, t = mid, idx = 0;
        while (idx < weights.size()) {
            int w = weights[idx];
            t -= w;
            if (t < 0) {
                cnt++;
                t = mid;
                if (cnt >= d) return false;
            } else {
                idx++;
            }
        }
        return true;
    }
};