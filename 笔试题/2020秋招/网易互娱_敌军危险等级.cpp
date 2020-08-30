#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

/**
 * 关键是考虑如何存储，
 * 考点，构建多叉树结构，然后寻找两节点的最近公共祖先
 */

int main() {
    int n;
    cin >> n;
    unordered_map<int, vector<int>> hash; // 采用邻接链表存储
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        hash[a].push_back(b);
        hash[b].push_back(a);
    }
    int k;
    cin >> k;
    vector<vector<int>> post;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        post.push_back({a, b});
    }

    queue<int> q;
    q.push(1);
    vector<bool> st(n + 1);
    unordered_map<int, PII> tree; // key存当前结点，键存父节点和当前结点的深度
    tree[1] = {0, 0};
    // bfs
    while (q.size()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            auto t = q.front();
            q.pop();
            for (auto nx : hash[t]) {
                if (!st[nx]) {
                    st[nx] = true;
                    q.push(nx);
                    tree[nx] = {t, tree[t].second + 1};
                }
            }
        }
    }

    vector<int> depth(n+1);
    for (int i = 1; i <= n; i++) {
        int a = i, b = i + 1;
        while (a != b) {
            if (tree[a].second > tree[b].second) a = tree[a].first;
            else b = tree[b].first;
        }
        depth[i] = a;
    }

    for (int i = 0; i < k; i++) {
        int a = post[i][0], b = post[i][1];
        // 两节点的最近公共祖先
        int minv = INT_MAX, res = 0;
        for (int i = a; i <b; i++) {
            if (minv > tree[depth[i]].second) {
                minv = tree[depth[i]].second;
                res = depth[i];
            }
        }
        cout<< res << endl;
    }
    return 0;
}