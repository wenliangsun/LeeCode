#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目354：俄罗斯套娃信封问题
 */
class LeeCode354 {
   public:
    /**
     * 对w升序排列，如果w相同按照h降序排序，因为w相同时，只能用一个信封，取h最大的
     */
    bool static compare(vector<int> v1, vector<int> v2) {
        if (v1[0] == v2[0]) {
            return v1[1] > v2[1];
        } else {
            return v1[0] < v2[0];
        }
    }

    /**
     * 思路：定义排序规则，问题转换成最长递增子序列
     */
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> dp(envelopes.size(), 1);
        // 按照高度  最长递增子序列
        for (int i = 0; i < envelopes.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < envelopes.size(); i++) {
            res = max(res, dp[i]);
        }
        return res;
    }

    /**
     * 时间复杂度：O(nlogn) 最长上升子序列采用二分查找的思路
     */
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), compare);
        vector<int> dp(e.size());
        int len = 0;
        for (int i = 0; i < e.size(); i++) {
            int l = 0, r = len;
            while (l < r) {
                int mid = l + r >> 1;
                if (dp[mid] >= e[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }
            if (l == len) len++;
            dp[l] = e[i][1];
        }
        return len;
    }
};