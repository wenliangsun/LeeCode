#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 题目：字符迷阵是一种经典的智力游戏。玩家需要在给定的矩形的字符迷阵中寻找特定的单词。
 * 在这题的规则中，单词是如下规定的：
 *  1. 在字符迷阵中选取一个字符作为单词的开头；
 *  2. 选取右方、下方、或右下45度方向作为单词的延伸方向；
 *  3. 以开头的字符，以选定的延伸方向，把连续得到的若干字符拼接在一起，则称为一个单词。
 * 题目链接：https://www.nowcoder.com/practice/8fb1e165abcb4b709d5a2f0ba759d0a6?tpId=98&tqId=32892&tPage=4&rp=4&ru=%2Fta%2F2019test&qru=%2Fta%2F2019test%2Fquestion-ranking
 * 注意这题，不是回溯法，因为它是对方向做了限制
 */

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        vector<string> arr;
        for (int i = 0; i < m; i++) {
            string temp;
            cin >> temp;
            arr.push_back(temp);
        }
        string key;
        cin >> key;
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == key[0]) {
                    //向右寻找
                    for (int k = 1; k < key.size(); k++) {
                        if (k + j >= n) break;
                        if (arr[i][k + j] != key[k]) break;
                        if (k == key.size() - 1) res++;
                    }
                    // 向下查找
                    for (int k = 1; k < key.size(); k++) {
                        if (i + k >= m) break;
                        if (arr[i + k][j] != key[k]) break;
                        if (k == key.size() - 1) res++;
                    }
                    // 向右下查找
                    for (int k = 1; k < key.size(); k++) {
                        if (i + k >= m || j + k >= n) break;
                        if (arr[i + k][j + k] != key[k]) break;
                        if (k == key.size() - 1) res++;
                    }
                }
            }
        }
        cout << res << endl;
    }
}