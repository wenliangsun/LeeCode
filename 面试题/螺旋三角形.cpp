#include <bits/stdc++.h>

using namespace std;

/**
 * 螺旋打印三角形
 */

// 下三角
vector<vector<int>> printTrigleDown(int n) {
    int dx[3] = {1, 0, -1}, dy[3] = {0, 1, -1};
    vector<vector<int>> res(n + 1, vector<int>(n));  // x方向多开一个空间
    int x = 0, y = 0, d = 0, cnt = 0, num = 1;
    for (int i = 0; i < n; i++) {
        cnt = n - i;
        while (cnt--) {
            d = i % 3;
            x = x + dx[d], y = y + dy[d];
            res[x][y] = num++;
        }
    }
    return res;
}

// 上三角
vector<vector<int>> printTrigleUp(int n) {
    int dx[3] = {0, 1, -1}, dy[3] = {1, -1, 0};
    vector<vector<int>> res(n, vector<int>(n + 1));  // y方向多开一个空间
    int x = 0, y = 0, d = 0, cnt = 0, num = 1;
    for (int i = 0; i < n; i++) {
        cnt = n - i;
        while (cnt--) {
            d = i % 3;
            x = x + dx[d], y = y + dy[d];
            res[x][y] = num++;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    // 打印时注意i的起始索引
    vector<vector<int>> resdown = printTrigleDown(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << resdown[i][j] << ' ';
        }
        cout << endl;
    }

    // 打印时注意j的起始索引
    vector<vector<int>> resup = printTrigleUp(n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << resup[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}