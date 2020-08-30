#include <bits/stdc++.h>

using namespace std;

/**
 * 翻转一棵树
 */

vector<vector<int>> inverse(vector<vector<int>> tree) {
    vector<vector<int>> res;
    stack<vector<int>> stk;
    stk.push(tree[0]);
    while (stk.size()) {
        auto t = stk.top();
        stk.pop();
        res.push_back(t);
        for (auto node : tree) {
            if (node[1] == t[0]) stk.push(node);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> tree = {{1, 0}, {2, 1}, {5, 2}, {6, 5},
                                {7, 5}, {3, 1}, {4, 1}};
    vector<vector<int>> res = inverse(tree);
    for (auto t : res) {
        cout << t[0] << ' ' << t[1] << endl;
    }
}