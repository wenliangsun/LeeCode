#include <bits/stdc++.h>

using namespace std;

/**
 * 已知一个字符串数组words，要求寻找其中两个没有重复字符的字符串，使得这两个字符串的长度乘积最大，输出这个最大的乘积
 *
 * 分割字符串
 * 判断字符串中是否有重复字符
 */
vector<string> split(string s) {
    vector<string> res;
    if (s.empty()) return res;
    s += ",";
    int pos = s.find(',');
    while (pos != s.npos) {
        res.push_back(s.substr(1, pos - 2));
        s = s.substr(pos + 1);
        pos = s.find(',');
    }
    return res;
}

bool isUnique(string s) {
    int m = 0;
    for (auto c : s) {
        if (m & (1 << (c - 'a'))) return false;
        m |= (1 << (c - 'a'));
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    int res = 0;
    if (s.empty())
        cout << res << endl;
    else {
        vector<string> w = split(s.substr(1, s.size() - 2));
        int res = 0;
        for (auto t1 : w) {
            for (auto t2 : w) {
                string t = t1 + t2;
                if (isUnique(t))
                    res = max(res, (int)t1.size() * (int)t2.size());
            }
        }
        cout << res << endl;
    }
    return 0;
}