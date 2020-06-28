#include <bits/stdc++.h>

using namespace std;

/**
 * 题目279：完全平方数
 */

class Solution {
   public:
    /**
     * 宽度优先搜索
     */
    int numSquares(int n) {
        vector<int> dist(n + 1, INT_MAX);  // 表示到0点的距离
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (q.size()) {
            int t = q.front();
            q.pop();
            if (t == n) return dist[t];
            for (int i = 1; t + i * i <= n; i++) {
                int j = t + i * i;
                // 更新距离
                if (dist[j] > dist[t] + 1) {
                    dist[j] = dist[t] + 1;
                    q.push(j);
                }
            }
        }
        return 0;
    }
};