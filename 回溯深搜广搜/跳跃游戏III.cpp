#include <bits/stdc++.h>

using namespace std;

/**
 * 跳跃游戏III
 */

class Solution {
   public:
    /**
     * 广度优先搜索，从起点开始搜索，遇到0返回true，如果没有可跳的且没有遇到零，则返回false
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> st(n);
        q.push(start);  // 起点入队
        while (q.size()) {
            int t = q.front();
            q.pop();
            if (arr[t] == 0) return true;
            st[t] = true;
            if (t + arr[t] < n && !st[t + arr[t]]) q.push(t + arr[t]); 
            if (t - arr[t] >= 0 && !st[t - arr[t]]) q.push(t - arr[t]);
        }
        return false;
    }
};