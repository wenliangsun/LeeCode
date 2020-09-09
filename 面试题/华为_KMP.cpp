#include <bits/stdc++.h>

using namespace std;

int KMP(string&s, string& p) {
    int m = p.size(), n = s.size();
    vector<int> fail(m, -1);
    for (int i = 1; i < m; i++) {
        int j = fail[i - 1];
        while (j != -1 && p[j + 1] != p[i]) j = fail[j];
        if (p[j + 1] == p[i]) fail[i] = j + 1;
    }
    int match = -1;
    for (int i = 0; i < n; i++) {
        while (match != -1 && p[match + 1] != s[i]) match = fail[match];
        if (p[match + 1] == s[i]) {
            match++;
            if (match == m - 1) return i - match;
        }
    }
    return -1;
}

int main() {
    string s = "aaabbbc";
    string p = "bc";
    int res = KMP(s, p);
    cout << res << endl;
    return 0;
}