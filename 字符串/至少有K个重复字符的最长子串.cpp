#include <bits/stdc++.h>

using namespace std;

int helper(string s, int k) {
    unordered_map<char, int> hash;
    for (auto c : s) hash[c]++;
    vector<int> split;
    for (int i = 0; i < s.size(); i++) {
        if (hash[s[i]] < k) split.push_back(i);
    }
    if (split.size() == 0) return s.size();
    int res = 0, l = 0;
    split.push_back(s.size());
    for (int i = 0; i < split.size(); i++) {
        int len = split[i] - l;
        if (len > res) res = max(res, helper(s.substr(l, len), k));
        l = split[i] + 1;
    }
    return res;
}

int main() {
    string s;
    while (cin >> s) {
        int k;
        cin >> k;
        cout << helper(s, k) << endl;
    }
    return 0;
}