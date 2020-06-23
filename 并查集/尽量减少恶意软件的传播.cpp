#include <bits/stdc++.h>

using namespace std;

/**
 * 题目924：尽量减少恶意软件的传播
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    vector<int> s;  // 连通区域的结点个数
    /**
     * 问题可以转换成求最大的且只包含一个感染结点的连通区域，这样删除该感染结点，其余的结点就不会再被感染了
     */
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        p = vector<int>(n);
        for (int i = 0; i < n; i++) p[i] = i;  // 初始化
        s = vector<int>(n);
        vector<int> affected(n);  // 记录联通区域中感染的结点个数
        sort(initial.begin(), initial.end());  // 先排序
        // 遍历图中的关系，进行union
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (graph[i][j]) Union(i, j);
        // 统计每个连通区域感染的结点数
        for (int i : initial) affected[Find(i)]++;
        int num = 0,
            res = -1;  // num记录最大连通区域的节点数，res是对应的结点索引
        for (int i : initial) {
            int root = Find(i);
            // 如果当前连通区域的感染结点是一个的话，说明该连通区域是可能的答案
            if (affected[root] == 1) {
                // 更新最大连通区域的结点数以及对应的感染结点索引
                if (num < s[root]) {
                    num = s[root];
                    res = i;
                }
            }
        }
        return res == -1 ? initial[0] : res;
    }

    int Find(int x) {
        if (x == p[x]) return x;
        p[x] = Find(p[x]);
        return p[x];
    }

    void Union(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);
        if (s[rx] < s[ry]) {
            p[rx] = ry;
            s[ry]++;
        } else {
            p[ry] = rx;
            s[rx]++;
        }
    }
};