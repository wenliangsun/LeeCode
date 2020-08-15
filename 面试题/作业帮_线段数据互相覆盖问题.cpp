#include <bits/stdc++.h>

using namespace std;

/**
 * 线段数据互相覆盖问题
 * 单个线段[2,6]可称为完全覆盖[4,6]，现有两组线段，判断A组能否完全覆盖B组
 * A : [[1, 3], [2, 6]] 
 * B : [[1, 4], [4, 5]] 
 * 返回 true
 * 
 * A ：[[1, 2], [4, 7]]
 * B ：[[2, 5], [6, 7]]
 * 返回 false
 */

class Solution {
    public:
    // 合并区间
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int idx = 0;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (res[idx][1] >= intervals[i][0]) res[idx][1] = max(res[idx][1], intervals[i][1]);
            else {
                res.push_back(intervals[i]);
                idx++;
            }
        }
        return res;
    }

    // 判断是否覆盖
    bool canCover(vector<vector<int>>& A, vector<vector<int>>& B) {
        A = merge(A);
        B = merge(B);
        // 两层for循环
        for (auto ta : A) {
            bool can = false;
            for (auto tb : B) {
                if (ta[0] <= tb[0] && ta[1] >= tb[1]) can = true;
            }
            if (!can) return false;
        }
        return true;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> A = {{1, 2}, {4, 7}};
    vector<vector<int>> B = {{2, 5}, {6, 7}};
    bool res = s.canCover(A, B);
    cout << res << endl;
    return 0;
}