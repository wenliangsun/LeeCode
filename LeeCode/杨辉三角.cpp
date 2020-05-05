#include <vector>

using namespace std;

/**
 * 题目118：杨辉三角
 */

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            vector<int> tmp;
            tmp.push_back(1);
            for (int j = 0; j < i - 1; j++) {
                int x = res[i - 1][j] + res[i - 1][j + 1];
                tmp.push_back(x);
            }
            if (i != 0) tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};