#include <bits/stdc++.h>

using namespace std;

/**
 * 题目119：杨辉三角II
 */

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 0; j < i - 1; j++) {
                int x = res[i - 1][j] + res[i - 1][j + 1];
                tmp.push_back(x);
            }
            if(i != 0)tmp.push_back(1);
            res.push_back(tmp);
        }
        return res[rowIndex];
    }
};