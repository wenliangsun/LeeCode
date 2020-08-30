#include <bits/stdc++.h>

using namespace std;

/**
 * 地铁迷在某个城市组织了地铁打卡活动。活动要求前往该城市中的所有地铁站进行打卡。打卡可以在站外或者站内进行。
 * 地铁的计价规则如下：只要不出站，就不计费；出站时，只计算进站和出站站点的距离。如在同一个站点进出站，
 * 按照最低票价 a 元计算。假设地铁票不会超时。大部分站点都是通过地铁线连通的，而且地铁站的连通是双向的
 * （若 A，B 连通，则 B，A连通），且具有传递性的（若 A，B 连通，且 B，C 连通，则 A，C连通）。
 * 但并不是所有的地铁站都相互连通，在不能通过坐地铁达到的两个地点间，交通的花费则提高到 b 元。
 * 地铁迷从酒店起点出发，再回到酒店。假设从酒店到达任意地铁站的交通花费为 b 元。
 * 请计算地铁迷完成打卡最小交通花费。
 * 
 * 并查集 找连通块
 */

vector<int> p;

int Find(int x) {
    if (x == p[x]) return x;
    p[x] = Find(p[x]);
    return p[x];
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    p = vector<int>(n);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        p[Find(x)] = Find(y);
    }
    unordered_set<int> hash;
    for (int i = 0; i < n; i++) hash.insert(Find(i));
    int res = hash.size() * a + (hash.size() - 1 + 2) * b;
    cout << res << endl;
    return 0;
}