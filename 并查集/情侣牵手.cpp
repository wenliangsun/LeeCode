#include <bits/stdc++.h>

using namespace std;

/**
 * 题目765：情侣牵手
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    int minSwapsCouples(vector<int>& row) {
        int m = row.size();
        p = vector<int>(m / 2);
        for (int i = 0; i < m / 2; i++) p[i] = i;  // 初始化
        int res = 0;
        for (int i = 0; i < m; i += 2)  // 将情侣合并
            p[find(row[i] / 2)] = find(row[i + 1] / 2);
        for (int i = 0; i < m / 2; i++)  // 判断里面有多少个环
            // 判断是否为环
            if (find(i) == i) res++;
        return m / 2 - res;
    }

    int find(int x) {
        if (x == p[x]) return x;
        // p[x] = find(p[x]);
        return find(p[x]);
    }
};