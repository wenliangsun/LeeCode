#include <bits/stdc++.h>

using namespace std;

/**
 * 题目952：按公因数计算最大组件大小
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        p = vector<int>(n);

        for (int i = 0; i < n; i++) p[i] = i;  // 初始化
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (gcd(A[i], A[j]) != 1) p[find(i)] = find(j);
            }
        }
        int res = 0;
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) res = max(res, ++cnt[find(i)]);
        return res;
    }
    // 求最大公约数
    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

    int find(int x) {
        if (x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }
};

/**
 * 优化版本
 */
class Solution2 {
   public:
    unordered_map<int, int> p;  // 根节点集合
    int largestComponentSize(vector<int>& A) {
        for (auto a : A)
            for (int k = 2; k * k <= a; k++) // 这儿优化了
                if (!(a % k)) p[find(k)] = p[find(a / k)] = p[find(a)];
        unordered_map<int, int> cnt;
        int res = 0;
        for (auto a : A) res = max(res, ++cnt[find(a)]);
        return res;
    }

    int find(int x) {
        if (!p.count(x)) return p[x] = x;
        if (x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }
};