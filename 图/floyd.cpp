#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, M = 100010, INF = 1000000000;

int n, m;
int d[N][N];  // 存储两点之间的最短距离

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) d[i][j] = i == j ? 0 : INF;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = min(c, d[a][b]);
    }
    // floyd 算法核心
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    cout << d[1][n] << endl;
    return 0;
}