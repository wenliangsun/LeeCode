#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
int m, n;

vector<PII> tmp;
vector<vector<bool>> st;
char flag;

void dfs(vector<string>& a, int x, int y) {
    tmp.push_back({x, y});
    st[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] == flag &&
            !st[nx][ny]) {
            dfs(a, nx, ny);
        }
    }
}

bool isValid(vector<string>& grid, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a <= 0 || a >= m - 1 || b <= 0 || b >= n - 1 || grid[a][b] != flag)
            return true;
    }
    return false;
}

int main() {
    cin >> m >> n;
    string s, pos;
    cin >> s;
    cin.ignore();
    getline(cin, pos);
    int t = pos.find(',');
    int x = stoi(pos.substr(1, t - 1));
    pos = pos.substr(t + 1);
    int y = stoi(pos.substr(0, pos.size() - 1));

    vector<string> grid;
    while (s.size()) {
        grid.push_back(s.substr(0, n));
        s = s.substr(n);
    }

    flag = grid[y][x];
    st = vector<vector<bool>>(m, vector<bool>(n));
    dfs(grid, y, x);

    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < tmp.size(); i++) {
        auto item = tmp[i];
        if (isValid(grid, item.first, item.second))
            cout << '(' << item.second << ',' << item.first << ')';
        if (i != tmp.size() - 1) cout << ',';
    }

    return 0;
}