#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1319：连通网络的操作次数
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    /**
     * 先将所有连接进行合并，然后找总共有多少个环，总共有多少个连通块，
     * 每一个环可以拆出来一根线来连接不同的连通块，所以，环的数量加1要大于等于连通块的数量
     */
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < n - 1) return -1; //如果网线的数量少于结点的数量减一，则肯定连不起来，直接返回-1
        p = vector<int>(n);
        for (int i = 0; i < n; i++) p[i] = i;  // 初始化
        for (auto ct : connections) p[find(ct[0])] = find(ct[1]);  // 合并
        unordered_set<int> hash; // 统计连通块
        int cnt = 0; // 记录环的数量
        for (int i = 0; i < n; i++) {
            int root = find(i);
            hash.insert(root); // 入哈希表
            if (root == i) cnt++; // 统计环
        }
        return cnt + 1 >= hash.size() ? hash.size() - 1 : -1;
    }

    int find(int x) {
        if (x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }
};