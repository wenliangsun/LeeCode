#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/**
 * 给定一个字符串（最多包含8个字符），可能包含重复的字母，返回有多少种不同的排列组合。
 */

int res = 0;
void dfs(string s, int begin, vector<bool>& used) {
    if (begin == s.size()) {
        res += 1;
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (used[i] || (i > 0 && s[i] == s[i - 1] && used[i - 1])) continue;
        used[i] = true;
        dfs(s, begin + 1, used);
        used[i] = false;
    }
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s.size() <= 0 || s.size() >= 8) {
            cout << 0 << endl;
            continue;
        }
        int len = s.size();
        res = 0;
        sort(s.begin(), s.end());
        vector<bool> used(s.size(), false);
        dfs(s, 0, used);
        cout << res << endl;
    }
    return 0;
}