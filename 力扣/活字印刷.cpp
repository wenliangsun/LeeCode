#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1079：活字印刷
 */

class Solution {
   public:
    int res = 0;
    vector<bool> st;
    /**
     * 回溯 + 去重
     */
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        st = vector<bool>(tiles.size());
        dfs(tiles);
        return res;
    }

    void dfs(string& tiles) {
        for (int i = 0; i < tiles.size(); i++) {
            if (i > 0 && tiles[i] == tiles[i - 1] && !st[i - 1]) continue;
            if (!st[i]) {
                st[i] = true;
                res++;
                dfs(tiles);
                st[i] = false;
            }
        }
    }
};