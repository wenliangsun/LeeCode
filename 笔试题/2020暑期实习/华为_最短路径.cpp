#include <stdio.h>

#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

/**
 * A要去B的城市找他玩，但是去B的城市有很多路径，A身上的钱也有限，
 * 请你帮他找到去B的城市的最短路径，路费也要足够。城市之间有单向的路径，
 * 每条路径有一定的路费。这题默认A在1号城市，B在N号城市。输出最短路径。
 * 如果钱不够到达B的城市，则输出-1.
 */

const int N = 110, M = 100010, INF = 100000000;

int g[N][N], dist[N];
int cost[N][N], val[N];
bool st[N];

int k, n, r;

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        val[i] = INF;
    }
    dist[1] = 0;
    val[1] = 0;
    for (int i = 0; i < n; i++) {
        int id, mind = INF;
        for (int j = 1; j <= n; j++) {
            // 这儿需要根据花费来选，选取到起点花费最小的点
            if (!st[j] && val[j] < mind) { 
                id = j;
                mind = val[j];
            }
        }
        st[id] = true;
        for (int j = 1; j <= n; j++) {
            if (val[j] > val[id] + cost[id][j]) {
                dist[j] = dist[id] + g[id][j];
                val[j] = val[id] + cost[id][j];
            } else if (val[j] > val[id] + cost[id][j] &&
                       dist[j] > dist[id] + g[id][j]) {
                dist[j] = dist[id] + g[id][j];
            }
        }
    }
}

int main() {
    while (cin >> k >> n >> r) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = INF;
                cost[i][j] = INF;
            }
        }
        for (int i = 0; i < r; i++) {
            int s, d, l, t;
            cin >> s >> d >> l >> t;
            g[s][d] = l;
            cost[s][d] = t;
        }
        dijkstra();
        // cout << dist[n] << ' ' << val[n] << endl;
        if (dist[n] != INF && val[n] < k) {
            cout << dist[n] << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}