#include <stdio.h>
#include <string.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/**
 * 函数a 的空间是30，函数a调用了函数b(空间是60)，函数b调用了函数c(空间是30)，
 * 则最大开销栈是30+60+30=120。
 */

vector<int> callnum, fsize;
vector<vector<int>> G;

int ans;

map<string, int> mp;
vector<bool> vis;

bool dfs(int cur, int sum) {
    vis[cur] = true;
    ans = max(ans, sum);
    for (int i = 0; i < G[cur].size(); ++i) {
        int nxt = G[cur][i];
        if (vis[nxt]) return false;
        bool ret = dfs(nxt, sum + fsize[nxt]);
        if (!ret) return false;
    }
    vis[cur] = false;
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        callnum.push_back(num);
    }
    int id = 0;
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        if (mp.count(name) == 0) {
            mp[name] = ++id;
        }
        int sz;
        cin >> sz;
        fsize.resize(id + 5);
        fsize[mp[name]] = sz;
        for (int j = 0; j < callnum[i]; ++j) {
            string s;
            cin >> s;
            if (mp.count(s) == 0) mp[s] = ++id;
            G.resize(id + 5);
            G[mp[name]].push_back(mp[s]);
        }
    }
    if (id != n) {
        cout << "NA" << endl;
        return 0;
    }
    vis.resize(id + 5);
    for (auto o : mp) {
        int enter = o.second;
        for (int i = 1; i <= id; ++i) vis[i] = false;
        bool ret = dfs(enter, fsize[enter]);
        if (!ret) {
            cout << "R" << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}