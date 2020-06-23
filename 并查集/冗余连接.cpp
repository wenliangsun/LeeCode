#include <bits/stdc++.h>

using namespace std;

/**
 * 题目684：冗余连接
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    /**
     * 并查集
     */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) p[i] = i;  // 初始化，自己指向自己
        for (auto e : edges) {
            // 查找，如果一条边的两个端点在一个集合中，说明构成回路了，直接返回
            if (find(e[0]) == find(e[1])) return {e[0], e[1]};
            p[find(e[0])] = find(e[1]);  // 合并
        }
        return {-1, -1};
    }

    /**
     * 查找函数
     */
    int find(int x) {
        if (x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }
};