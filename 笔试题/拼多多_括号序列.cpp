#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 拼多多题目：现在给出两个不保证合法的由圆括号组成的字符串，
 * 你需要交错这两个圆括号序列（在组成的新字符串中，
 * 每个初始字符串都保持原来的顺序）得到一个新的合法的圆括号表达式
 * （不同的交错方式可能得到相同的表达式，这种情况分开计数），
 * 求共有多少结果合法的交错方式（无法得到合法的圆括号表达式则输出0），
 * 输出结果对109+7取模后的值。
 */

const int N = 2510;
const int mod = 1e9 + 7;

/**
 * 统计括号的前缀和 遇到左括号+1右括号-1
 * 合法括号：此过程中前缀和一直大于等于0，最终前缀和等于0
 */
void get_prefix_sum(string s, vector<int>& sum) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            sum[i + 1] = sum[i] + 1;
        } else {
            sum[i + 1] = sum[i] - 1;
        }
    }
}

int main() {
    string a;
    string b;
    // 动态数组dp[i][j] 表示a中前i和b中前j个括号组成的合法括号的数量
    vector<vector<int>> dp(N, vector<int>(N, 0));
    getline(cin, a);
    getline(cin, b);
    vector<int> as(N, 0);
    vector<int> bs(N, 0);
    get_prefix_sum(a, as);
    get_prefix_sum(b, bs);
    // 判断前缀和是否合法
    if (as[a.size()] + bs[b.size()] != 0) {
        puts("0");
    } else {
        for (int i = 0; i <= a.size(); i++) {
            for (int j = 0; j <= b.size(); j++) {
                // 如果是空串，合法  base case
                if (!i && !j) {
                    dp[i][j] = 1;
                } else {
                    // 否则，先判断是否合法
                    if (as[i] + bs[j] >= 0) {
                        // dp[i][j]
                        // 可以由dp[i-1][j](表示在组合的后面加了a中的括号)
                        // 和dp[i][j-1](表示在组合的最后面加了b中的括号)得来
                        if (i) dp[i][j] += dp[i - 1][j];
                        if (j) dp[i][j] += dp[i][j - 1];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
        cout << dp[a.size()][b.size()] << endl;
    }
    return 0;
}