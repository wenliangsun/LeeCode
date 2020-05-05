#include <iostream>

using namespace std;

/**
 * 给你n个点，m条无向边，每条边都有长度d和花费p，给你起点s终点t，
 * 要求输出起点到终点的最短距离及其花费，如果最短距离有多条路线，
 * 则输出花费最少的。
 */

const int N = 1010, M = 100010, INF = 1000000000;

int g[N][N], dist[N];
int cost[N][N], val[N];
bool st[N];

int n, m, s;

void dijkstra(int s) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        val[i] = INF;
    }
    dist[s] = 0;
    val[s] = 0;

    for (int i = 0; i < n; i++) {
        int id, mind = INF;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && dist[j] < mind) {
                mind = dist[j];
                id = j;
            }
        }
        st[id] = 1;
        for (int j = 1; j <= n; j++) {  // 更新最短路径和花费
            if (dist[j] > dist[id] + g[id][j]) {
                dist[j] = dist[id] + g[id][j];
                val[j] = val[id] + cost[id][j];
                // 如果路径相同，更新花费
            } else if (dist[j] == dist[id] + g[id][j] &&
                       val[j] > val[id] + cost[id][j]) {
                val[j] = val[id] + cost[id][j];
            }
        }
    }
}

int main() {
    while (cin >> n >> m) {
        if (n == 0 || m == 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = INF;
                cost[i][j] = INF;
            }
        }
        for (int i = 0; i < m; i++) {
            int a, b, d, p;
            cin >> a >> b >> d >> p;
            if (g[a][b] > d) {  //   去除重复边，选最短的
                g[a][b] = g[b][a] = d;
                cost[a][b] = cost[b][a] = p;
            } else if (g[a][b] == d && cost[a][b] > p) {
                // 去除重复花费，选最小的
                cost[a][b] = cost[b][a] = p;
            }
        }
        int s, t;
        cin >> s >> t;
        dijkstra(s);
        cout << dist[t] << ' ' << val[t] << endl;
    }
    return 0;
}