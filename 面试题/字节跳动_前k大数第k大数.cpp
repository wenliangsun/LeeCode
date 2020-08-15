#include <bits/stdc++.h>

using namespace std;

/**
 * 第k大数，第k小，前k小，前k大数，中位数都是一个思路，用快排的思想，时间复杂度是O(N)
 */

class Solution {
   public:
    /**
     * 第k大
     * 堆。优先队列
     * 时间复杂度：O(nlogk)
     * 空间复杂度：O(k)
     */
    int largestK(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, greater<int>> q; // 小顶堆，用于第k大
        priority_queue<int, vector<int>, less<int>> q; // 大顶堆，用于第k小
        for (auto n : nums) {
            q.push(n);
            if (q.size() > k) q.pop();
        }
        return q.top();
    }

    /**
     * 利用快排的思路去寻找位置k-1，使得它前面的比它小(大)，它后面的比它大(小)
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int largestK2(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int idx = -1;
        while (idx != k - 1) {
            idx = partition(nums, l, r);
            if (idx < k - 1) l = idx + 1;
            else if (idx > k -1) r = idx -1;
            else break;
        }
        return nums[k - 1];
    }

    int partition(vector<int>& nums, int l, int r) {
        int flag = l;
        int idx = l + 1;
        for (int i = idx; i <= r; i++) {
            if (nums[i] > nums[flag]) { // 换一下比较规则即可
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        swap(nums[idx - 1], nums[flag]);
        return idx - 1;
    }

    /**
     * 前k大和前k小
     * 时间复杂度：O(nlogk)
     * 空间复杂度：O(k)
     */
    vector<int> largestKnum(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> q;
        for (auto n : nums) {
            q.push(n);
            if (q.size() > k) q.pop();
        }
        vector<int> res;
        while (q.size()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }

    /**
     * 利用快排的思路去寻找位置k-1，使得它前面的比它小(大)，它后面的比它大(小)
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    vector<int> largestKnum2(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int idx = -1;
        while (idx != k - 1) {
            idx = partition(nums, l, r);
            if (idx < k - 1) l = idx + 1;
            else if (idx > k - 1) r = idx - 1;
            else break;
        }
        return vector<int>(nums.begin(), nums.begin() + k);
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {1, 45, 3, 22, 332, 112, 12, 0, 34};
    int res = s.largestK2(nums, 3);
    cout << res << endl;
    vector<int> res2 = s.largestKnum2(nums, 3);
    for (auto n : res2) cout << n << ' ';
    return 0;
}
