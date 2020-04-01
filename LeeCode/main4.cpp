#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "LeeCode1143.h"
#include "LeeCode300.h"
#include "LeeCode516.h"
#include "LeeCode651.h"
#include "LeeCode877.h"

using namespace std;

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main() {
    // vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    // LeeCode300 coder300 = LeeCode300();
    // int res = coder300.lengthOfLIS2(nums);
    // cout << res << endl;

    // LeeCode516 coder516 = LeeCode516();
    // string s = "bbbab";
    // int res = coder516.longestPalindromeSubseq(s);
    // cout << res << endl;

    // LeeCode877 coder877 = LeeCode877();
    // vector<int> nums = {5, 3, 4, 5};
    // bool res = coder877.stoneGame(nums);
    // cout << res << endl;

    // LeeCode651 coder651 = LeeCode651();
    // int res = coder651.maxA(7);
    // cout << res << endl;

    LeeCode1143 coder1143 = LeeCode1143();
    string text1 = "abc";
    string text2 = "def";
    int res = coder1143.longestCommonSubsequence(text1, text2);
    cout << res << endl;

    return 0;
}