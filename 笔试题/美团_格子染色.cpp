#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目：在二维平面上有一个无限的网格图形，初始状态下，所有的格子都是空白的。
 * 把以这两个网格为端点的区间内的所有网格染黑（包含这两个端点）。
 * 问经过n次操作以后，共有多少个格子被染黑，重复染色同一格子只计数一次。
 *
 * 思路：区间重叠问题
 */

// 保存行和列线段
struct Segement {
    int k;
    int l, r;
    // 运算符重载
    bool operator<(const Segement& W) const {
        // 排行
        if (k != W.k) {
            return k < W.k;
        }
        // 排列
        if (l != W.l) {
            return l < W.l;
        }
        // 同行  同列
        return r < W.r;
    }
};

const int N = 10010;

typedef long long LL;

// 合并区间
LL merge(vector<Segement>& q) {
    sort(q.begin(), q.end());
    LL res = 0;
    for (int i = 0; i < q.size();) {
        int j = i;
        // 寻找同一行或列的区间
        while (j < q.size() && q[j].k == q[i].k) j++;
        int l = -2e9, r = l - 1;
        // 合并同一行的区间
        for (int k = i; k < j; k++) {
            if (r < q[k].l) {
                res += r - l + 1;
                l = q[k].l, r = q[k].r;
            } else {
                r = max(r, q[k].r);
            }
        }
        res += r - l + 1;
        i = j;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<Segement> rows, cols;
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            cols.push_back({x1, min(y1, y2), max(y1, y2)});
        } else {
            rows.push_back({y1, min(x1, x2), max(x1, x2)});
        }
    }

    LL res = merge(rows) + merge(cols);
    // 排除行和列交错的格子
    for (auto r : rows) {
        for (auto c : cols) {
            if (r.k >= c.l && r.k <= c.r && c.k >= r.l && c.k <= r.r) {
                res--;
            }
        }
    }
    cout << res << endl;
}