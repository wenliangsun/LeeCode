#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1202：交换字符串中的元素
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    /**
     * 首先将可以交换的位置合并成不同的集合，然后按照位置取出字母，并对其进行排序
     * 将排好序的字母再插回到原来的索引位置即可。
     */
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        p = vector<int>(n);
        for (int i = 0; i < n; i++) p[i] = i;             // 初始化
        for (auto t : pairs) p[find(t[0])] = find(t[1]);  // 合并可以交换的位置
        vector<vector<char>> tmp(n);  // 按索引求出每个集合中的字母
        for (int i = 0; i < n; i++) {
            int root = find(i);
            tmp[root].push_back(s[i]);
        }
        for (int i = 0; i < n; i++) {  // 对取出的字母按照降序排列
            sort(tmp[i].begin(), tmp[i].end());
            reverse(tmp[i].begin(), tmp[i].end());
        }

        string res;
        // 构建答案
        for (int i = 0; i < n; i++) {
            int root = find(i);       // 首先找当前字符的根
            res += tmp[root].back();  // 从当前根的集合中取最小的字母
            tmp[root].pop_back();  // 从当前根的集合中删除当前字母
        }
        return res;
    }

    int find(int x) {
        if (x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }
};