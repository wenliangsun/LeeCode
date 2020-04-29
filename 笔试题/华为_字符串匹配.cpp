#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 输入一串字符串，找出特定字符串后面的特定类型的值，
 * 保证'['前的字符要和第一个关键词就是read 是一样的，
 * 中间也要保证十六进制。
 */

struct Info {
    string addr;
    string mask;
    string val;
};

string content, pattern;
vector<Info> res;

bool check16(string s) {
    int len = s.size();
    if (len < 3) return false;
    int idx = 0;
    if (s[idx] != '0') return false;
    ++idx;
    if (s[idx] != 'x' && s[idx] != 'X') return false;
    ++idx;
    string num = s.substr(idx);
    for (int i = 0; i < num.size(); ++i) {
        char ch = num[i];
        if (ch >= '0' && ch <= '9') continue;
        if (ch >= 'A' && ch <= 'F') continue;
        if (ch >= 'a' && ch <= 'f') continue;
        return false;
    }
    return true;
}

void check(string s) {
    int len = s.size();
    string head = s.substr(0, pattern.size());
    if (head != pattern) return;
    int idx = pattern.size();
    if (idx < len && s[idx] != '[') return;
    idx++;
    if (s.substr(idx, 5) != "addr=") return;
    idx += 5;
    int pos = s.find(',', idx);
    if (pos == s.npos || !check16(s.substr(idx, pos - idx))) return;
    string addr = s.substr(idx, pos - idx);
    idx = pos + 1;
    if (s.substr(idx, 5) != "mask=") return;
    idx += 5;
    pos = s.find(',', idx);
    if (pos == s.npos || !check16(s.substr(idx, pos - idx))) return;
    string mask = s.substr(idx, pos - idx);
    idx = pos + 1;
    if (s.substr(idx, 4) != "val=") return;
    if (!check16(s.substr(idx))) return;
    string val = s.substr(idx);
    res.push_back({addr, mask, val});
}

void solve(string s) {
    int len = s.size();
    s += ',';
    int idx = 0;
    while (idx <= len) {
        int pos = s.find("],", idx);
        if (pos == s.npos) break;
        check(s.substr(idx, pos - idx));
        idx = pos + 2;
    }
}

int main() {
    cin >> pattern >> content;
    solve(content);
    if (res.size() == 0) {
        cout << "FAIL" << endl;
    } else {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i].addr << ' ' << res[i].mask << ' ' << res[i].val
                 << endl;
        }
    }
    return 0;
}