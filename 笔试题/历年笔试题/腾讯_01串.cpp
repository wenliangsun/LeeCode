#include <iostream>
#include <string>

using namespace std;
/**
 * 腾讯题目：给定一个仅包含0或1的字符串，现在可以对其进行一种操作
 * 当有两个相邻的字符其中有一个是0另外一个是1的时候，可以消除掉这两个字符。
 * 这样的操作可以一直进行下去直到找不到相邻的0和1为止。
 * 问这个字符串经历了操作以后的最短长度。
 * 
 * 思路：只要存在0和1 必定可以消除
 * 
 */

int main() {
    int n;
    string str;
    cin >> n >> str;
    int ones = 0, zeros = 0;
    for (auto c : str) {
        if (c == '0') {
            zeros++;
        } else {
            ones++;
        }
    }
    cout << abs(zeros - ones) << endl;
    return 0;
}