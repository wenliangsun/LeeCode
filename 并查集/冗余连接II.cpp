#include <bits/stdc++.h>

using namespace std;

/**
 * 题目685：冗余连接II
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    /**
     * 并查集
     * 分三种情况，无环但有一个结点的入度为2，有环且环中节点的入度为2，有环但入度都为1
     */
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) p[i] = i;  // 初始化，自己指向自己
        vector<int> d(n + 1);                   // 统计入度
        vector<int> res1, res2;  // 记录前一个和后一个的边
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (d[e[1]] > 0) {
                res1 = {d[v], v};
                res2 = e;
                e[0] = e[1] = -1;
            }
            d[v] = u;
        }
        for (auto e : edges) {
            if (e[0] < 0 || e[1] < 0) continue;  // 跳过后一个的边
            // 查找
            if (find(e[0]) == find(e[1])) return res1.empty() ? e : res1;
            p[find(e[0])] = find(e[1]);  //合并
        }
        return res2;
    }

    int find(int x) {
        if (x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }
};