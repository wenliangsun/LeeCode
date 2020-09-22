#include <bits/stdc++.h>

using namespace std;

/**
 * 跳跃游戏IV
 */

class Solution {
   public:
    /**
     * 广度优先搜索。
     */
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < n; i++) hash[arr[i]].push_back(i);  //存储相同的值位置
        vector<int> dist(n, 0);         // 记录距离
        queue<int> q;
        q.push(0);
        dist[0] = 1;  // 初始距离记为1同时也用来标记位置是否已跳过
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (t && !dist[t - 1]) {  // 左跳
                q.push(t - 1);
                dist[t - 1] = dist[t] + 1;
            }
            if (t != n - 1 && !dist[t + 1]) {  // 右跳
                q.push(t + 1);
                dist[t + 1] = dist[t] + 1;
            }
            if (hash.count(arr[t])) {  // 相等数字跳
                for (auto u : hash[arr[t]]) {
                    if (!dist[u]) {
                        q.push(u);
                        dist[u] = dist[t] + 1;
                    }
                }
                hash.erase(arr[t]);  // 一旦发生了同值跳跃，任何同值的都不会再被跳跃，删除键
            }
        }
        return dist[n - 1] - 1;  // 因为起点是1，所以最后的答案需要减一
    }
};