#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 510, M = 100010, INF = 100000000;

int h[N], e[M], w[M], ne[M], idx;  // 邻接表存储所有边
int dist[N];                       // 存储所有点到1号点的最短距离
bool st[N];  // 存储每个点的最短距离是否已确定

int n, m;  // 点的数量

// 添加一条边
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void Dijkstra() {
    // 注意这儿的初始化！！！
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});  // first存储距离，second存储节点编号
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    Dijkstra();
    if (dist[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }
    return 0;
}