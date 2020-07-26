#include <bits/stdc++.h>

using namespace std;

/**
 * 最接近0的子数组和
 */

class Solution {
   public:
    typedef pair<int, int> PII;
    /**
     * 前缀和
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    vector<int> subarraySumClosest(vector<int> nums) {
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1];
        unordered_map<int, PII> hash;
        int res = INT_MAX;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (abs(pre[j] - pre[i - 1]) < res) {
                    res = abs(pre[j] - pre[i - 1]);
                    if (!hash.count(res)) hash[res] = {i, j};
                }
            }
        }
        return {hash[res].first - 1, hash[res].second - 1};
    }

    /**
     * 前缀和+排序，则两个前缀和最近接的的话，其之间的子数组和越接近与0，所以对前缀和排序
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(n)
     */
    vector<int> subarraySumClosest2(vector<int> nums) {
        int n = nums.size();
        int t = 0;
        vector<PII> sum;
        sum.push_back({0, 0});
        for (int i = 0; i < n; i++) {
            t += nums[i];
            sum.push_back({t, i + 1}); // 坐标是从1开始的
        }
        sort(sum.begin(), sum.end()); // 排序
        int a = -1, b = -1, diff = INT_MAX;
        for (int i = 1; i < sum.size(); i++) {
            if (abs(sum[i].first - sum[i - 1].first) < diff) {
                diff = abs(sum[i].first - sum[i - 1].first);
                // 注意这儿 pre[j] - pre[i] 计算的是[i+1，j]区间的和
                a = min(sum[i].second, sum[i - 1].second); // 这儿应该是 a - 1 + 1
                b = max(sum[i].second, sum[i - 1].second) - 1; // 这儿需要减一
            }
        }
        return {a, b};
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {-3, 1, 1, -3, 5};
    vector<int> res = s.subarraySumClosest2(nums);
    for (auto n : res) cout << n << ' ';
}