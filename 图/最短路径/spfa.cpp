#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, M = 100010, INF = 100000000;

int h[N], e[M], w[M], ne[M], idx;  // 邻接表
int dist[N], q[N];  // dist表示每个点到起点的距离, q 是队列
bool st[N];         // 存储每个点是否在队列中

int n, m;

int add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa() {
    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    q[tt++] = 1;
    st[1] = 1;
    while (hh != tt) {
        int t = q[hh++];
        st[t] = 0;
        if (hh == n) hh = 0;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    st[j] = 1;
                    q[tt++] = j;
                    if (tt == n) tt = 0;
                }
            }
        }
    }
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    spfa();
    if (dist[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }
    return 0;
}