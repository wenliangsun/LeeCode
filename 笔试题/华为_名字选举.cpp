#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/**
 * 输入一串字符串，表示人名，输出票数最多的人的名字，
 * 票数一样多的按首字母先后顺序，先后顺序一样的，
 * 名字短的在前面，其中每个人名只有首字母大写，用逗号隔开。
 */

typedef pair<string, int> PII;

vector<PII> names;
map<string, int> m;

bool check(string s) {
    if (s.empty()) return false;
    if (s[0] < 'A' || s[0] > 'Z') return false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] < 'a' || s[i] > 'z') return false;
    }
    m[s]++;
    return true;
}

bool split(string s) {
    int len = s.size();
    if (!len) return false;
    s += ' ';
    string cur;
    int p = 0;
    while (p <= len) {
        if (s[p] == ' ') {
            bool ok = check(cur);
            if (!ok) return false;
            cur = "";
        } else {
            cur += s[p];
        }
        p++;
    }
    return true;
}

bool cmp(PII p1, PII p2) {
    if (p1.second != p2.second) return p1.second > p2.second;
    if (p1.first.size() == p2.first.size()) return p1.first < p2.first;
    if (p1.first.find(p2.first) != p1.first.npos) return false;
    if (p2.first.find(p1.first) != p2.first.npos) return true;
    return p1.first < p2.first;
}

int main() {
    string s;
    getline(cin, s);
    bool isValid = split(s);
    if (!isValid) {
        cout << "error.0001" << endl;
    } else {
        for (auto item : m) {
            names.push_back({item.first, item.second});
        }
        sort(names.begin(), names.end(), cmp);
        cout << names[0].first << endl;
    }
    return 0;
}