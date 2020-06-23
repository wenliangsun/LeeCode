#include <bits/stdc++.h>

using namespace std;

/**
 * 题目547：朋友圈
 */

class UnionFind {
   public:
    vector<int> p;
    UnionFind(int n) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int Find(int x) {
        if (x == p[x]) return x;
        p[x] = Find(p[x]);
        return p[x];
    }

    void Union(int a, int b) { p[Find(a)] = Find(b); }
};

class Solution {
   public:
    vector<int> p;  // 根节点集合
    /**
     * 并查集
     */
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        p = vector<int>(n);
        for (int i = 0; i < n; i++) p[i] = i;  // 初始化，自己指向自己
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (M[i][j]) p[find(i)] = find(j);  // 合并

        unordered_set<int> hash;
        for (int i = 0; i < n; i++) hash.insert(find(i));  // 查找
        return hash.size();
    }

    // 查找
    int find(int n) {
        if (n == p[n]) return n;
        p[n] = find(p[n]);
        return p[n];
    }

    /**
     * 使用类的并查集
     */
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFind uf = UnionFind(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (M[i][j]) uf.Union(i, j);
        unordered_set<int> hash;
        for (int i = 0; i < n; i++) hash.insert(uf.Find[i]);
        return hash.size();
    }
};