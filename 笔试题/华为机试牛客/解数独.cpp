#include <iostream>
#include <vector>

using namespace std;

/**
 * 解数独  回溯法 穷举
 */

// 判断[r, c]位置能否放置v
bool isValid(vector<vector<int>>& b, int r, int c, int v) {
    for (int i = 0; i < 9; i++) {
        if (b[r][i] == v) return false;
        if (b[i][c] == v) return false;
        if (b[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == v) return false;
    }
    return true;
}

bool dfs(vector<vector<int>>& b, int x, int y) {
    int n = 9, m = 9;
    //如果当前行到边界了，转下一行
    if (y == m) return dfs(b, x + 1, 0);
    // 如果下一行到边界了，说明已完成，返回
    if (x == n) return true;
    // 如果当前位置已有值，则跳过
    if (b[x][y] != 0) return dfs(b, x, y + 1);
    // 穷举当前位置可以出现的数字
    for (int i = 1; i <= 9; i++) {
        if (isValid(b, x, y, i)) {
            // 回溯的思想！！！
            b[x][y] = i;
            if (dfs(b, x, y + 1)) return true;
            b[x][y] = 0;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> b(9, vector<int>(9));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) cin >> b[i][j];
    dfs(b, 0, 0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}