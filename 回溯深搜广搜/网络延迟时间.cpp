#include <bits/stdc++.h>

using namespace std;

/**
 * 题目743：网络延迟时间
 */

class Solution {
   public:
    vector<vector<int>> g;
    vector<int> dist;
    vector<bool> st;
    int INF = 100000000;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        g = vector<vector<int>>(N + 5, vector<int>(N + 5, INF));
        dist = vector<int>(N + 5, INF);
        st = vector<bool>(N + 5);
        for (auto t : times) {
            g[t[0]][t[1]] = t[2];
        }
        dijkstra(K, N);
        int res = 0;
        for (int i = 1; i <= N; i++) res = max(res, dist[i]);
        return res == INF ? -1 : res;
    }
    void dijkstra(int k, int n) {
        dist[k] = 0;
        for (int i = 0; i < n; i++) {
            int idx, mind = INF;
            for (int j = 1; j <= n; j++) {
                if (!st[j] && dist[j] < mind) {
                    idx = j, mind = dist[j];
                }
            }
            st[idx] = true;
            for (int j = 1; j <= n; j++) {
                dist[j] = min(dist[j], dist[idx] + g[idx][j]);
            }
        }
    }
};