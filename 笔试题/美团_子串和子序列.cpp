#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

const int M = 1000000007;
int f[5001][5001], ns, nt;
string s, t;

int main() {
    cin >> s >> t;
    ns = s.size();
    nt = t.size();

    unordered_map<char, int> cnt;
    unordered_map<char, vector<int>> value;
    for (int j = 1; j <= nt; ++j) {
        char tt = t[j - 1];
        cnt[tt]++;
        if (value.find(tt) == value.end()) {
            value[tt].resize(ns + 1);
        }
        for (int i = 1; i <= ns; ++i) {
            char ss = s[i - 1];
            f[i][j] = cnt[ss];
            if (value.find(ss) != value.end()) {
                f[i][j] = (f[i][j] + value[ss][i - 1]) % M;
            }
            value[tt][i] = (value[tt][i] + f[i][j - 1]) % M;
        }
    }

    int ans = 0;
    for (int i = 1; i <= ns; ++i) {
        ans = (ans + f[i][nt]) % M;
    }
    cout << ans;
    return 0;
}