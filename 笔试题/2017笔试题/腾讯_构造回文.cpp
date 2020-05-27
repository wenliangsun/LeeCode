#include <iostream>
#include <string>

using namespace std;

/**
 * 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
 * 输出需要删除的字符个数
 *
 * 考察最长回文子序列！！！
 */

const int N = 1010;

int dp[N][N];

int main() {
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        cout << s.size() - dp[0][s.size() - 1] << endl;
    }
    return 0;
}