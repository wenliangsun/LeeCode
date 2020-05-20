#include <bits/stdc++.h>

using namespace std;

unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                 {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                 {'8', "tuv"}, {'9', "wxyz"}};

vector<string> res;

void dfs(string s, int b, string t) {
    if (b == s.size()) res.push_back(t);
    string ss = m[s[b]];
    for (auto c : ss) {
        dfs(s, b + 1, t + c);
    }
}

int main() {
    string s;
    while (cin >> s) {
        string t;
        dfs(s, 0, t);
    }
    return 0;
}