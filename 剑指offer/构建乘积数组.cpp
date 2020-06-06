#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 用原来的数组记录从前向后的累积和 使用这个代码！！！
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> res(n, 1);
        int t = 1;
        // 从前向后累积，记录在答案数组中
        for (int i = 1; i < n; i++) {
            t *= a[i - 1];
            res[i] *= t;
        }
        t = 1;
        // 从后向前累积，记录在答案数组中
        for (int i = n - 2; i >= 0; i--) {
            t *= a[i + 1];
            res[i] *= t;
        }
        return res;
    }

    /**
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     * 因为用了数组来存储了累积，可以进一步优化成O(1)的空间复杂度
     */
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n + 1), pos(n + 1), res(n);
        pre[0] = 1, pos[n] = 1;
        for (int i = 0; i < n; i++) pre[i + 1] = i == 0 ? a[i] : pre[i] * a[i];
        for (int i = n - 1; i >= 0; i--)
            pos[i] = i == n - 1 ? a[i] : pos[i + 1] * a[i];
        for (int i = 0; i < a.size(); i++) res[i] = pre[i] * pos[i + 1];
        return res;
    }
};