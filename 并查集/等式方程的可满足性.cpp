#include <bits/stdc++.h>

using namespace std;

/**
 * 题目990：等式方程的可满足性
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    bool equationsPossible(vector<string>& equations) {
        p = vector<int>(26);                    // 26个字母
        for (int i = 0; i < 26; i++) p[i] = i;  // 初始化
        for (auto& s : equations) {
            if (s[1] == '=') {  // 将相等的进行合并
                p[find(s[0] - 'a')] = find(s[3] - 'a');
            }
        }
        for (auto& s : equations) {
            if (s[1] == '!') {  // 判断不等时，两个变量是否是在不同的连通块中
                if (find(s[0] - 'a') == find(s[3] - 'a')) return false;
            }
        }
        return true;
    }

    int find(int x) {
        if (x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }
};