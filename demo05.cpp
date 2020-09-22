#include <iostream>

using namespace std;

/**
 * 给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为正值。
 * 请你求出1号点到n号点的最短距离，如果无法从1号点走到n号点，则输出-1。
 * https://www.acwing.com/problem/content/description/851/
 */

const int N = 2010, M = 50010, INF = 1000000000;

int g[N][N];
int dis[N];
int st[N];

int n, m, k;

void dijkstra() {
    for (int i = 1; i <= n; i++) dis[i] = INF;
    dis[1] = 0;
    for (int i = 0; i < n; i++) {
        int id, mind = INF;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && dis[j] < mind) {
                mind = dis[j];
                id = j;
            }
        }
        st[id] = 1;
        for (int j = 1; j <= n; j++) dis[j] = min(dis[j], dis[id] + g[id][j]);
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) g[i][j] = INF;

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
        g[y][x] = min(g[y][x], z);
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 0;
    }

    dijkstra();
    if (dis[n] == INF)
        cout << -1 << endl;
    else
        cout << dis[n] << endl;
    
    return 0;
}