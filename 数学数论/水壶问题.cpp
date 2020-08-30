#include <bits/stdc++.h>

using namespace std;

/**
 * 题目365：水壶问题
 */

class Solution {
   public:
    /**
     * 数学法 贝祖定理，最大公约数，最小公倍数
     */
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        int t = gcd(x, y);
        return z % t == 0;

    }

    int gcd(int x, int y) {
        return y ? gcd(y, x % y) : x;
    }

    /**
     * bfs搜索
     */
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        queue<int> q;
        unordered_set<int> hash;
        q.push(0);
        hash.insert(0);
        int d[4] = {x, -x, y, -y};
        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (t == z) return true;
            for (int i = 0; i < 4; i++) {
                int a = max(0, min(x + y, t + d[i]));
                if (!hash.count(a)) q.push(a);
                hash.insert(a);
            }
        }
        return false;
    }
};