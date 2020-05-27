#include <bits/stdc++.h>

using namespace std;

/**
 * 小易在学校中学习了关于字符串的理论, 于是他基于此完成了一个字典的项目。
 * 小易的这个字典很奇特, 字典内的每个单词都包含n个'a'和m个'z',
 * 并且所有单词按照字典序排列。 小易现在希望你能帮他找出第k个单词是什么。
 * 1<=k<=1e9
 */

typedef long long LL;

int n, m, k;

string s, res;
int cnt = 0;
vector<bool> st;

/**
 * 回溯 + 剪枝 会超时
 */
void dfs(int idx, string path) {
    if (idx == s.size()) {
        res = path;
        cnt++;
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (st[i] || (i > 0 && s[i] == s[i - 1] && st[i - 1])) continue;
        if (cnt < k) {
            st[i] = true;
            path.push_back(s[i]);
            dfs(idx + 1, path);
            st[i] = false;
            path.pop_back();
        }
    }
}
/**
 * 思路：排列组合
 * n个a和m个z 只能组成C(n+m,n)个单词
 * 1.假设第一个单词是a，则剩下的n-1个a和m个z组成的单词数为C(n-1+m,n-1)，且是字典中前C(n-1+m,n-1)个单词
 * 2.比较k和C(n-1+m,n-1)，若k小于等于C(n-1+m,n-1),则说明第一个字母一定是a，问题转化为在n-1个a和m个z中找第k个单词。
 * 3.若k大于C(n-1+m,n-1),则说明第一个字母一定是z，单词是以z开头的第k-C(n-1+m,n-1)个单词，问题转化为在n个a和m-1个z中找第k-C(n+m-1,n-1)个单词
 */
int main() {
    cin >> n >> m >> k;
    string res;
    // 每次迭代 问题规模都缩减一个单位
    while (n && m) {
        LL cnt = 1;
        // 求组合数
        for (int i = 0; i < n - 1; i++) {
            cnt *= n - 1 + m - i;
            cnt /= (i + 1);
            if (cnt > k) break;  // 如果当前组合数大于k，直接跳出
        }
        if (k <= cnt) {  //如果k小于等于cnt，则表明首字符的确应为a
            res.push_back('a');
            n--;  //问题缩减为 n-1个a和m个z中找第k大
        } else {
            res.push_back('z');
            m--;  //问题缩减为 n个a和m-1个z 中找第k-cnt大
            k -= cnt;
        }
    }
    //循环结束后，剩余子序列只存在"aa..aaa" 或 "zz..zzz"1种情况
    if (k != 1)
        cout << -1 << endl;
    else {
        while (n--) res.push_back('a');
        while (m--) res.push_back('z');
        cout << res << endl;
    }

    // st = vector<bool>(n + m);
    // string s1(n, 'a');
    // string s2(m, 'z');
    // s = s1 + s2;
    // string path;
    // dfs(0, path);
    // if (cnt <= k)
    //     cout << res << endl;
    // else
    //     cout << -1 << endl;
    return 0;
}