#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            g[i][j] = x;
        }
    }
    vector<int> row(n), col(n);
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) row[i] += g[i][j];
    for (int j = 0; j < n; ++j) 
        for (int i = 0; i < n; ++i) col[j] += g[i][j];
    for (int k = 1; k <= n; ++k) {
        int a = 0, b = 0, mv = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[0].size(); j++) {
                if ((row[i] + col[j] - g[i][j] > mv)) {
                    a = i, b = j;
                    mv = row[i] + col[j] - g[i][j];
                }
            }
        }
        vector<vector<int>> tmp(g.size() - 1, vector<int>(g.size() - 1));
        int x = 0, y = 0;
        for (int i = 0; i < g.size(); i++) {
            if (i == a) continue;
            y = 0;
            for (int j = 0; j < g.size(); j++) {
                if (j == b) continue;
                tmp[x][y] = g[i][j];
                y++;
            }
            x++;
        }
        g = tmp;
        vector<int> trow(x), tcol(x);
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < x; ++j) {
                trow[i] += g[i][j];
            }
        }
        for (int j = 0; j < x; ++j) {
            for (int i = 0; i < x; ++i) {
                tcol[j] += g[i][j];
            }
        }
        row = trow, col = tcol;
        cout << a + 1 << ' ' << b + 1 << endl;
    }
    return 0;
}