#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Knuth-Morris-Pratt 算法
 */
class KMP {
   public:
    int search(string str, string pattern) {
        int M = pattern.size();
        int N = str.size();
        // 动态数组 dp[状态][字符] = 下个状态
        vector<vector<int>> dp(M, vector<int>(256, 0));
        // base case
        dp[0][pattern[0]] == 1;
        // 影子状态X初始化为0
        int X = 0;
        // 当前状态j从1开始
        for (int j = 1; j < M; j++) {
            for (int c = 0; c < 256; c++) {
                if (pattern[j] == c) {
                    dp[j][c] = j + 1;
                } else {
                    dp[j][c] = dp[X][c];
                }
            }
            // 更新影子状态
            X = dp[X][pattern[j]];
        }
        // pattern 初始状态为0
        int j = 0;
        for (int i = 0; i < N; i++) {
            // 计算pattern的下一个状态
            j = dp[j][str[i]];
            // 如果pattern到达终点，匹配成功，返回结果
            if (j == M) {
                return i - M + 1;
            }
        }
        // 没有到达终点，匹配失败
        return -1;
    }
};
