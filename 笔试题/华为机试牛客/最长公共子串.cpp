#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        if (s1.size() > s2.size()) {
            string t = s1;
            s1 = s2;
            s2 = t;
        }
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[0]) dp[i][0] = 1;
        }
        for (int j = 0; j < s2.size(); j++) {
            if (s2[j] == s1[0]) dp[0][j] = 1;
        }
        int start = 0, mx = 0;
        for (int i = 1; i < s1.size(); i++) {
            for (int j = 1; j < s2.size(); j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > mx) {
                        mx = dp[i][j];
                        start = i - mx + 1;
                    }
                } else
                    dp[i][j] = 0;
            }
        }
        cout << s1.substr(start, mx) << endl;
    }
    return 0;
}