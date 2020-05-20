#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        // 两个哈希表
        unordered_map<char, int> need, window;
        for (auto c : t) need[c]++;
        int l = 0, r = 0, idx = 0;
        int matched = 0, minLen = INT_MAX;
        while (r < s.size()) {
            auto c = s[r];
            // 如果需求字符串包含当前字符，则入窗口
            if (need.count(c)) {
                window[c]++;
                // 统计窗口中和需求字符串的匹配字符数
                if (window[c] == need[c]) matched++;
            }
            r++;
            // 如果窗口已经满足需求，则缩小窗口大小
            while (matched == need.size()) {
                // 更新最小覆盖子串长度
                if (r - l < minLen) {
                    minLen = r - l;
                    idx = l;
                }
                auto c = s[l];
                // 缩小窗口
                if (need.count(c)) {
                    window[c]--;
                    if (window[c] < need[c]) matched--;
                }
                l++;
            }
        }
        string res = minLen == INT_MAX ? "" : s.substr(idx, minLen);
        cout << res << endl;
    }
    return 0;
}