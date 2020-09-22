#include <bits/stdc++.h>

using namespace std;

bool match(string& s, string& p) {
    int m = p.size(), n = s.size();
    vector<int> fail(m, -1);
    for (int i = 1; i < m; i++) {
        int j = fail[i - 1];
        while (j != -1 && p[j + 1] != p[i]) j = fail[j];
        if (p[j + 1] == p[i]) fail[i] = j + 1;
    }
    int mc = -1;
    for (int i = 0; i < n; i++) {
        while (mc != -1 && p[mc + 1] != s[i]) mc = fail[mc];
        if (p[mc + 1] == s[i]) mc++;
        if (mc == m - 1) return true;
    }
    return false;
}

int main() {
    string s = "abcabcdefg";
    string p = "cdee";
    bool res = match(s, p);
    cout << res << endl;
}