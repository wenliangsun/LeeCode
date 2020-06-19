#include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个字符串M和一个整数k，可以删除M中任意k个字符，返回字典序最小的那一个作为秘钥。
 */

void dfs(int k, string m, string& res) {
    if (k == 0) {
        res = min(res, m);
        return;
    }
    int i;
    for (i = 0; i < m.size() - 1; i++) {
        if (m[i] > m[i + 1]) {
            string tmp = m;
            m.erase(i, 1);
            if (m < res) dfs(k - 1, m, res);
            m = tmp;
        }
    }
    if (i == m.size() - 1 && k > 0) dfs(0, m.erase(m.size() - k), res);
}

int main() {
    string m;
    int k;
    while (cin >> m >> k) {
        string res = m;
        dfs(k, m, res);
        cout << res << endl;
    }
    return 0;
}