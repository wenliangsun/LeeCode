#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
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