#include <bits/stdc++.h>

using namespace std;

/**
 * 题目839：相似字符串组
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        p = vector<int>(n);
        for (int i = 0; i < n; i++) p[i] = i;  // 初始化
        // 单词两两合并
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (similar(A[i], A[j])) p[find(i)] = find(j);
        unordered_set<int> hash;
        // 统计最后有多少个连通块
        for (int i = 0; i < n; i++) hash.insert(find(i));
        return hash.size();
    }

    int find(int x) {
        if (x == p[x]) return x;
        p[x] = find(p[x]);  // 路径压缩优化很关键，不优化会超时
        return p[x];
    }

    bool similar(string& s1, string& s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i]) cnt++;
        return cnt <= 2;
    }
};