#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 1; i < n; i++) cin >> b[i];
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + a[i - 1];
            if (i > 1) dp[i] = min(dp[i], dp[i - 2] + b[i - 1]);
        }
        int s = dp[n];
        int h = s / 3600;
        int m = s % 3600 / 60;
        int ss = s % 3600 % 60 % 60;
        int hh = h + 8;
        string time = hh > 12 ? "pm" : "am";
        string res;
        res += hh > 9 ? to_string(hh) : "0" + to_string(hh);
        res += ":";
        res += m > 9 ? to_string(m) : "0" + to_string(m);
        res += ":";
        res += ss > 9 ? to_string(ss) : "0" + to_string(ss);
        cout << res << ' ' << time << endl;
    }
    return 0;
}