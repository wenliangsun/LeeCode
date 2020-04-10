#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>

/**
 * 题目：公司的程序员不够用了，决定把产品经理都转变为程序员以解决开发时间长的问题。在给定的矩形网格中，每个单元格可以有以下三个值之一：
 * 值0代表空单元格;
 * 值1代表产品经理;
 * 值2代表程序员;
 * 每分钟，任何与程序员(在4个正方向上)相邻的产品经理都会变成程序员。
 * 返回直到单元格中没有产品经理为止所必须经过的最小分钟数。
 * 如果不可能，返回-1。
 * 
 * 思路：多源最短路径问题  BFS！！！
 */

using namespace std;

const int N = 15;

typedef pair<int, int> PII; // 存储位置

int n, m;
int g[N][N]; // 分布
int dist[N][N]; // 距离

int bfs() {
    queue<PII> que;
    memset(dist, -1, sizeof dist);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 2) {
                dist[i][j] = 0;
                que.push({i, j});
            }
        }
    }
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (que.size()) {
        auto t = que.front();
        que.pop();
        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 1 &&
                dist[a][b] == -1) {
                dist[a][b] = dist[x][y] + 1;
                que.push({a, b});
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 1) {
                if (dist[i][j] == -1) return -1;
                res = max(res, dist[i][j]);
            }
        }
    }
    return res;
}

int main() {
    // 不定长读取！！！
    string line;
    while (getline(cin, line)) {
        int k = 0;
        stringstream ssin(line);
        while (ssin >> g[n][k]) k++;
        m = k;
        n++;
    }

    cout << bfs() << endl;
}
