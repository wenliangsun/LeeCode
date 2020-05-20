#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> strs;
    string s;
    while (cin >> s) {
        strs.push_back(s);
    }
    unordered_map<string, vector<string>> hash;
    // 关键是构建一个标准作为他们的键  这儿选择对他们进行排序
    for (auto str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        hash[key].push_back(str);
    }
    vector<vector<string>> res;
    for (auto item : hash) {
        res.push_back(item.second);
    }
    for (int i = 0; i < res.size(); i++) {
        for (auto s : res[i]) {
            cout << s;
        }
        cout << endl;
    }
    return 0;
}