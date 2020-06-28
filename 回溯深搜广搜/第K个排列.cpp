#include <bits/stdc++.h>

using namespace std;

/**
 * 题目60：第K个排列
 */
class LeeCode60 {
   public:
    int cnt = 0;
    string res;
    vector<bool> st;
    string getPermutation(int n, int k) {
        st = vector<bool>(n);
        string path;
        string num;
        for (int i = 1; i <= n; i++) num += to_string(i);
        dfs(num, k, 0, path);
        return res;
    }

    void dfs(string& num, int k, int idx, string& path) {
        if (idx == num.size()) {
            cnt++;
            if (cnt == k) res = path;
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (!st[i] && cnt < k) {
                path.push_back(num[i]);
                st[i] = true;
                dfs(num, k, idx + 1, path);
                path.pop_back();
                st[i] = false;
            }
        }
    }

    string getPermutation(int n, int k) {
        vector<int> t;
        for (int i = 1; i <= n; i++) t.push_back(i);
        string ans;
        while (t.size() > 0) {
            int tn = t.size();
            int count = jie(tn - 1);
            tn = (k - 1) / count;
            ans += to_string(t[tn]);
            k = k - count * tn;
            t.erase(t.begin() + tn);
        }
        return ans;
    }

    int jie(int n) {
        int ans = 1;
        while (n) ans *= n--;
        return ans;
    }

    // 直接调用库函数
    string getPermutation(int n, int k) {
        string nums;
        for (int i = 1; i <= n; i++) nums += to_string(i);
        for (int i = 0; i < k - 1; i++) next_permutation(nums.begin(), nums.end());
        return nums;
    }
};