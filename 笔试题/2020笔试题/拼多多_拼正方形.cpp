#include <bits/stdc++.h>

using namespace std;

/**
 * N个木棍（1~N），第i个木棍长$L_i$，用完所有木棍，拼出正方形，
 * 一共T组，有些无解，判断T组是否有解，有YES，无NO。
 */

const int N = 25;

int nums[N];
bool vis[N];
int n;

// 剪枝更彻底
bool dfs2(int idx, int sum) {
    if (sum == 0) return true;
    if (idx == n) return false;
    for (int i = idx; i < n; i++) {
        if (vis[i] || nums[i] > sum) continue;
        vis[i] = true;
        if (dfs2(i + 1, sum - nums[i])) return true;
        vis[i] = false;
    }
    return false;
}

bool dfs(int idx, int a, int b, int c, int d, int sum) {
    if (idx == n) {
        if (a == sum && b == sum && c == sum && d == sum)
            return true;
        else
            return false;
    }
    // 排序就是为了这儿的剪枝
    if (a > sum || b > sum || c > sum || d > sum) return false;
    return dfs(idx + 1, a + nums[idx], b, c, d, sum) ||
           dfs(idx + 1, a, b + nums[idx], c, d, sum) ||
           dfs(idx + 1, a, b, c + nums[idx], d, sum) ||
           dfs(idx + 1, a, b, c, d + nums[idx], sum);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> nums[i];
        // 排序是为了更快的剪枝
        sort(nums, nums + n), reverse(nums, nums + n);
        int sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % 4) return false;
        // if (dfs(0, 0, 0, 0, 0, sum / 4))
        //     cout << "YES" << endl;
        // else
        //     cout << "NO" << endl;

        bool can = true;
        for (int i = 0; i < 4; i++) {
            if (!dfs2(0, sum / 4)) can = false;
        }
        if (can)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}