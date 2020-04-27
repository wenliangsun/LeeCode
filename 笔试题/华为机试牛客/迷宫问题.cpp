#include <iostream>
#include <vector>

using namespace std;

/**
 * 它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，
 * 不能斜着走，要求编程序找出从左上角到右下角的最短路线。
 * 入口点为[0,0],既第一空格是可以走的路
 *
 * 类似与单词搜索， 采用回溯法
 */

typedef pair<int, int> PII;

vector<PII> res;

// 回溯法
void dfs(vector<vector<int>> &a, int x, int y, vector<PII> &path) {
    int tmp = a[x][y];
    a[x][y] = -1;
    path.push_back({x, y});
    int r = a.size(), c = a[0].size();
    if (x == r - 1 && y == c - 1) {
        if (res.empty() || path.size() < res.size()) {
            res = path;
        }
    }

    if (x - 1 >= 0 && a[x - 1][y] == 0) dfs(a, x - 1, y, path);
    if (x + 1 < r && a[x + 1][y] == 0) dfs(a, x + 1, y, path);
    if (y - 1 >= 0 && a[x][y - 1] == 0) dfs(a, x, y - 1, path);
    if (y + 1 < c && a[x][y + 1] == 0) dfs(a, x, y + 1, path);
    a[x][y] = tmp;
    path.pop_back();
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> a(n, vector<int>(m));
        res.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        vector<PII> path;
        dfs(a, 0, 0, path);
        for (int i = 0; i < res.size(); i++) {
            auto t = res[i];
            cout << '(' << t.first << ',' << t.second << ')' << endl;
        }
    }
    return 0;
}