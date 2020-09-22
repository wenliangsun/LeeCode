#include <bits/stdc++.h>

using namespace std;

/**
 * 判断二分图
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    /**
     * 并查集
     * 如果当前结点与和它相邻的结点处于同一个集合时，返回false，否则合并它的相邻结点
     * 时间复杂度：(N+M)
     * 空间复杂度：O(N)
     */
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        p = vector<int>(n);
        for (int i = 0; i < n; i++) p[i] = i;  // 初始化
        for (int i = 0; i < n; i++) {
            int x = find(i);  // 当前结点
            for (auto b : graph[i]) {
                int y = find(b);  // 相邻结点
                if (x == y) return false;
                p[find(graph[i][0])] = find(b);  // 合并相邻结点
            }
        }
        return true;
    }

    int find(int x) {
        if (x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }

    /**
     * 深搜
     * 连通域染色问题，相同的区域染一种颜色，用dfs染联通的区域，如果遇到与它相邻的结点染的颜色相同，说明不是二分图
     * 时间复杂度：O(M+N)
     * 空间复杂度：O(N)
     */
    vector<int> st; // 标记访问记录 0表示未访问，1表示一种颜色，-1表示另一种颜色
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        st = vector<int>(n);
        for (int i = 0; i < n; i++) { // 可能包含多个连通域，如果顶点没有被访问过，则dfs
            if (st[i] == 0 && !dfs(graph, i, 1)) return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, int v, int c) {
        if (st[v] != 0) return st[v] == c; // 如果当前结点已经被访问了， 那么判断当前结点已经染的颜色与要染的颜色是否一致
        st[v] = c; // 当前节点染色
        for (auto w : graph[v]) { // 遍历当前结点的相邻结点
            if (!dfs(graph, w, -c)) return false; // 将相邻结点染成另一种颜色即-c。
        }
        return true;
    }

    /**
     * 广搜
     * 时间复杂度：O(N+M)
     * 空间复杂度：O(N)
     */
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> st(n);
        queue<int> q;
        for (int i = 0; i < n; i++) { // 可能有多个连通域
            if (st[i] == 0) { // 如果当前顶点没有被染色
                q.push(i); // 入队
                st[i] = 1; // 染色
                while (q.size()) {
                    int t = q.front();
                    q.pop();
                    for(auto w : graph[t]) { // 与其相邻的节点染成另一种颜色
                        if (st[w] == st[t]) return false; // 如果相邻的节点与当前结点染色一样返回false
                        if (st[w] == 0) {
                            st[w] = -st[t];
                            q.push(w); // 相邻节点入队
                        }
                    }

                }
            }      
        }
        return true;
    }
};