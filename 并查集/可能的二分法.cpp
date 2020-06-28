#include <bits/stdc++.h>

using namespace std;

/**
 * 题目886：可能的二分法
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    /**
     * 运用种类并查集的思想，开两倍的数组，前半部分存放可以分在一组的人，后半部分存放自己不喜欢的人。
     */
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        p = vector<int>(N * 2 + 5); // 并查集
        for (int i = 1; i < N * 2 + 5; i++) p[i] = i;  // 初始化
        for (auto item : dislikes) {
            int x = find(item[0]); // 查找自己的根节点
            int y = find(item[1]);
            int a = find(item[0] + N); // 查找自己不喜欢人的根节点
            int b = find(item[1] + N);
            if (x == y) // 如果这两个人已经在一组了，不可以！！！返回false
                return false;
            else { // 否则，将不喜欢的人合并
                p[a] = y;
                p[b] = x;
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