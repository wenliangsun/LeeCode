#include <bits/stdc++.h>

using namespace std;

/**
 * 跳跃游戏系列
 */

class Solution {
   public:
    /**
     * 跳跃游戏I 判断你是否能够到达最后一个位置。
     * 贪心，对每一个能作为起跳点的格子都尝试跳一次，把能跳到最远的距离不断更新。
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxPos) return false;
            maxPos = max(maxPos, nums[i] + i);
        }
        return true;
    }

    /**
     * 跳跃游戏II 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
     * 贪心 ：每次在可以跳的范围内选择一个跳的最远的位置。
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int jump(vector<int>& nums) {
        int end = 0, maxPos = 0, res = 0;
        // 这儿注意，如果start和end刚好在数组末尾相遇，是不需要加1的，因此小于nums.size() - 1;
        for (int start = 0; start < nums.size() - 1; start++) { 
            maxPos = max(maxPos, nums[start] + start); // 寻找start到end区间可以跳的最远的位置
            if (start == end) { // 如果start遇到了end说明前一跳的区间已经扫描完了，也求得前一跳的范围内可以跳到的最远位置
                end = maxPos; // 把end更新为可以跳到的最远的位置
                res++; // 跳跃次数加 1
            }
        }
        return res;
    }

    /**
     * 跳跃游戏III
     * 你最开始位于该数组的起始下标 start 处。当你位于下标 i 处时，你可以跳到 i + arr[i] 或者 i - arr[i]。
     * 请你判断自己是否能够跳到对应元素值为 0 的 任一下标处。
     * 广度优先搜索：从起点开始搜索，遇到0则返回true，当没有可跳的并且没遇到0时，返回false
     */
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> st(n);
        q.push(start);
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (arr[t] == 0) return true;
            st[t] = true;
            if (t + arr[t] < n && !st[t + arr[t]]) q.push(t + arr[t]);
            if (t - arr[t] >= 0 && !st[t - arr[t]]) q.push(t - arr[t]);
        }
        return false;
    }

    /**
     * 跳跃游戏IV
     * 可以左跳，右跳和相等数字跳，到达数组末尾最少跳跃次数。
     * 广度优先搜索。
     */
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < n; i++) hash[arr[i]].push_back(i); //存储相同的值位置
        vector<int> dist(n, 0); // 记录距离
        queue<int> q;
        q.push(0);
        dist[0] = 1; // 初始距离记为1同时也用来标记位置是否已跳过
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (t && !dist[t - 1]) { // 左跳
                q.push(t - 1);
                dist[t - 1] = dist[t] + 1;
            }
            if (t != n - 1 && !dist[t + 1]) { // 右跳
                q.push(t + 1);
                dist[t + 1] = dist[t] + 1;
            }
            if (hash.count(arr[t])) { // 相等数字跳
                for (auto u : hash[arr[t]]) {
                    if (!dist[u]) {
                        q.push(u);
                        dist[u] = dist[t] + 1;
                    }
                }
                hash.erase(arr[t]); // 一旦发生了同值跳跃，任何同值的都不会再被跳跃，删除键
            }
        }
        return dist[n - 1] - 1; // 因为起点是1，所以最后的答案需要减一
    }
};