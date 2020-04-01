#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 题目560：和为k的子数组
 */
class LeeCode560 {
   public:
    /**
     * 思路：前缀和技巧
     * 时间复杂度：O(N^2)
     * 空间复杂度：O(N)
     * 可优化
     * 有问题，有负数的时候不对
     */
    int subarraySum(vector<int>& nums, int k) {
        int sum[nums.size() + 1];
        sum[0] = 0;
        // 构造前缀和
        for (int i = 0; i < nums.size(); i++) {
            sum[i + 1] = sum[i] + nums[i];
            cout << sum[i + 1] << endl;
        }
        int res = 0;
        // 暴力列举所有情况
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                cout << sum[i] << " " << sum[j] << endl;
                if (sum[i] - sum[j] == k) {
                    res++;
                }
            }
        }
        return res;
    }

    /**
     * 思路：前缀和和hash表
     */
    int subarraySum2(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> preSum;  // 记录前缀和和其出现的次数
        preSum[0] = 1;
        int res = 0;
        int sum0_i = 0;
        for (int i = 0; i < n; i++) {
            // 计算前缀和
            sum0_i += nums[i];
            // 计算要找的前缀和
            int sum0_j = sum0_i - k;
            // 如果前面有这个前缀和，则直接更新答案
            if (preSum.count(sum0_j)) {
                res += preSum[sum0_j];
            }
            // 把前缀和存入map并记录次数
            preSum[sum0_i]++;
        }
        return res;
    }
};

int main() {
    LeeCode560 code = LeeCode560();
    vector<int> nums = {-1, -1, 1};
    int res = code.subarraySum2(nums, 0);
    cout << res << endl;
}