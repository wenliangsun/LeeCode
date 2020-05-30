#include <bits/stdc++.h>

using namespace std;

/**
 * 小明有一袋子长方形的积木，如果一个积木A的长和宽都不大于另外一个积木B的长和宽，则积木A可以搭在积木B的上面。
 * 好奇的小明特别想知道这一袋子积木最多可以搭多少层，你能帮他想想办法吗？
 * 定义每一个长方形的长L和宽W都为正整数，并且1 <= W <= L <= INT_MAX,
 * 袋子里面长方形的个数为N, 并且 1 <= N <= 1000000.
 *
 * 思路：先对一个边进行升序排序，如果边相等的话，按另一边进行升序排序。
 * 然后对另一边求最长增长子序列。
 * 注意：这个题卡时间，如果采用O(n^2)时间复杂度的方法会超时，需要用O(nlogn)时间复杂度的算法
 */

const int N = 1000010;
typedef long long LL;
typedef pair<LL, LL> PII;

LL n;

int main() {
    cin >> n;
    vector<PII> b;
    for (int i = 0; i < n; i++) {
        int w, l;
        cin >> w >> l;
        b.push_back({w, l});
    }
    sort(b.begin(), b.end());
    // 最长增长子序列  时间复杂度O(n^2) 超时！！！需要用O(nlogn)的方法
    // vector<int> dp(n);
    // for (int i = 0; i < n; i++) {
    //     dp[i] = 1;
    //     for (int j = 0; j < i; j++)
    //         if (b[j].second <= b[i].second) dp[i] = max(dp[i], dp[j] + 1);
    // }
    // int res = 0;
    // for (int i = 0; i < n; i++) res = max(res, dp[i]);
    // cout << res << endl;

    // 最长增长子序列 时间复杂度：O(nlogn)
    vector<int> dp(n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = l + r >> 1;
            if (dp[mid] > b[i].second)
                r = mid;
            else
                l = mid + 1;
        }
        if (l == len) len++;
        dp[l] = b[i].second;
    }
    cout << len << endl;

    return 0;
}