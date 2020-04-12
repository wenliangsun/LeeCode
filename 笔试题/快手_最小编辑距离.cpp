#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 最小编辑距离
 * 
 */

class MinEditDistence {
   public:
    int minDistence(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = 0; i <= s1.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= s2.size(); j++) {
            dp[0][j] = j;
        }
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                if (s1[i] == s2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = min(
                        min(dp[i + 1][j] + 1, dp[i][j + 1] + 1), dp[i][j] + 1);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main() {
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    MinEditDistence mindist = MinEditDistence();
    int res = mindist.minDistence(s1, s2);
    cout << res << endl;
}