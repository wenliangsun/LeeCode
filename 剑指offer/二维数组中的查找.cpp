#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     *  还可以用二分法
     */
    bool findNumberIn2DArray(vector<vector<int>>& m, int t) {
        if (!m.size()) return false;
        int r = 0, c = m[0].size() - 1;
        while (r < m.size() && c >= 0) {
            if (m[r][c] == t)
                return true;
            else if (m[r][c] > t)
                c--;
            else
                r++;
        }
        return false;
    }
};