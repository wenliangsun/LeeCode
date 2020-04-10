#include <iostream>

using namespace std;

/**
 * 题目：蛇形矩阵
 */

const int N = 110;
int n, m;
int res[N][N];
bool visited[N][N];

int main() {
    cin >> n >> m;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int x = 0, y = 0, d = 0;
    for (int i = 1; i <= n * m; i++) {
        int nx = x + dx[d], ny = y + dy[d];  // 计算下一次的位置
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
            d = (d + 1) % 4;  // 换方向
            nx = x + dx[d], ny = y + dy[d];
        }
        res[x][y] = i;         // 当前位置赋值
        visited[x][y] = true;  // 当前位置标记
        x = nx, y = ny;        // 更新
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}