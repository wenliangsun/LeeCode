#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 最长公共子串
 */

int main() {
    string temp;
    getline(cin, temp);
    int index = temp.find(',');
    string s1 = temp.substr(0, index);
    string s2 = temp.substr(index + 1, temp.size() - index);
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[0]) {
            dp[i][0] = 1;
        }
    }
    for (int j = 0; j < s2.size(); j++) {
        if (s2[j] == s1[0]) {
            dp[0][j] = 1;
        }
    }
    int res = 0;
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    cout << res << endl;
    return 0;
}