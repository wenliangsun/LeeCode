#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> res;

// 判断是否是回文
bool check(string s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
    }
    return true;
}

void dfs(string s, int begin, vector<string> path) {
    if (s.size() == begin) {
        res.push_back(path);
        return;
    }
    for (int i = begin; i < s.size(); i++) {
        // 注意这儿 可以进一步优化
        if (!check(s, begin, i)) continue;
        path.push_back(s.substr(begin, i - begin + 1));
        dfs(s, i + 1, path);
        path.pop_back();
    }
}

int main() {
    string s;
    while (cin >> s) {
        res.clear();
        vector<string> path;
        dfs(s, 0, path);
        for (int i = 0; i < res.size(); i++) {
            for (auto s : res[i]) {
                cout << s << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}