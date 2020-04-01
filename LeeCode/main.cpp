// #include <climits>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "LeeCode01.h"
#include "LeeCode03.h"
#include "LeeCode05.h"
#include "LeeCode06.h"
#include "LeeCode07.h"
#include "LeeCode08.h"
#include "LeeCode09.h"
#include "LeeCode10.h"
#include "LeeCode11.h"
#include "LeeCode12.h"
#include "LeeCode14.h"
#include "LeeCode15.h"
#include "LeeCode16.h"
#include "LeeCode17.h"
#include "LeeCode18.h"
#include "LeeCode20.h"
#include "LeeCode22.h"
#include "LeeCode26.h"
#include "LeeCode27.h"
#include "LeeCode28.h"
#include "LeeCode29.h"
#include "LeeCode30.h"
#include "LeeCode31.h"
#include "LeeCode32.h"
#include "LeeCode33.h"
#include "LeeCode34.h"
#include "LeeCode35.h"
#include "LeeCode36.h"
#include "LeeCode38.h"
// #include "LeeCode39.h"
#include "LeeCode40.h"
#include "LeeCode41.h"
#include "LeeCode42.h"
#include "LeeCode43.h"
#include "LeeCode44.h"
#include "LeeCode46.h"
#include "LeeCode47.h"
#include "LeeCode48.h"
#include "LeeCode49.h"
#include "LeeCode50.h"

// #define INT_MAX pow(2, 31);

using namespace std;

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main() {
    // LeeCode01 code1 = LeeCode01();
    // vector<int> arr{2, 7, 11, 15};
    // vector<int> res = code1.twoSum02(arr, 9);
    // cout << res.size() << endl;
    // cout << res[0] << " " << res[1] << endl;

    LeeCode03 coder3 = LeeCode03();
    string str = "abba";
    int res = coder3.lengthOfLongestSubstring2(str);
    cout << res << endl;

    // LeeCode05 coder5 = LeeCode05();
    // string str = "cbbd";
    // string res = coder5.longestPalindrome(str);
    // cout <<"######"<< str.substr(0,3) << endl;

    // LeeCode06 coder6 = LeeCode06();
    // string str = "LEETCODEISHIRING";
    // string res = coder6.convert(str, 3);
    // cout << res << endl;

    // LeeCode07 coder7 = LeeCode07();
    // int res = coder7.reverse(1534236469);
    // cout << res << endl;

    // LeeCode08 coder8 = LeeCode08();
    // string str = "42";
    // int res = coder8.myAtoi(str);
    // cout << res << endl;

    // LeeCode09 coder9 = LeeCode09();
    // bool res = coder9.isPalindrome(123);
    // cout << res << endl;

    // LeeCode10 coder10 = LeeCode10();
    // string str = "aa";
    // string p = "a*";
    // bool res = coder10.isMatch02(str, p);
    // cout << res << endl;

    // LeeCode11 coder11 = LeeCode11();
    // vector<int> arr{1,1};
    // int res = coder11.maxArea(arr);
    // cout << res << endl;

    // LeeCode12 coder12 = LeeCode12();
    // string res = coder12.intToRoman(12);
    // cout << res << endl;

    // LeeCode14 coder14 = LeeCode14();
    // vector<string> strs{"a"};
    // string res = coder14.longestCommonPrefix(strs);
    // cout << res << endl;

    // LeeCode15 coder15 = LeeCode15();
    // vector<int> arr{-1, 0, 1, 2, -1, -4};
    // vector<vector<int> > res = coder15.threeSum02(arr);
    // for (int i = 0; i < res.size(); i++) {
    //     printArray(res[i]);
    // }

    // LeeCode16 coder16 = LeeCode16();
    // vector<int> arr{-1, 2, 1, -4};
    // int res = coder16.threeSumClosest(arr, 1);
    // cout << res << endl;

    // LeeCode17 coder17 = LeeCode17();
    // string digits = "23";
    // vector<string> res = coder17.letterCombinations(digits);
    // for (int i = 0; i < res.size(); i++) {
    //     cout << res[i] << endl;
    // }

    // LeeCode18 coder18 = LeeCode18();
    // vector<int> arr{1, 0, -1, 0, -2, 2};
    // vector<vector<int> > res = coder18.fourSum(arr, 0);
    // for (int i = 0; i < res.size(); i++) {
    //     printArray(res[i]);
    // }

    // LeeCode20 coder20 = LeeCode20();
    // string str = "";
    // bool res = coder20.isValid(str);
    // cout << res << endl;

    // LeeCode22 coder22 = LeeCode22();
    // vector<string> res = coder22.generateParenthesis02(3);
    // for (int i = 0; i < res.size(); i++) {
    //     cout << res[i] << endl;
    // }

    // LeeCode26 coder26 = LeeCode26();
    // LeeCode27 coder27 = LeeCode27();
    // vector<int> arr{0, 1, 2, 2, 3, 0, 4, 2};
    // int res = coder27.removeElement(arr, 2);
    // printArray(arr);
    // cout << res << endl;

    // LeeCode28 coder28 = LeeCode28();
    // string str = "hello";
    // string substr = "ll";
    // int res = coder28.strStr(str, substr);
    // cout << res << endl;

    // LeeCode29 coder29 = LeeCode29();
    // int res = coder29.divide(-2147483648, -1);
    // cout << res << endl;

    // LeeCode30 coder30 = LeeCode30();
    // vector<string> words{"word","good","best","word"};
    // string s = "wordgoodgoodgoodbestword";
    // vector<int> res = coder30.findSubstring(s, words);
    // printArray(res);

    // LeeCode31 coder31 = LeeCode31();
    // vector<int> arr{2,3, 1};
    // printArray(arr);
    // coder31.nextPermutation(arr);
    // printArray(arr);

    // LeeCode32 coder32 = LeeCode32();
    // string s =
    //     "()()(()(())((()))(())))()(())))()))))(()))))()))))())))(())))()((())))"
    //     ")()(()))()((()))))())))()))))(((()(((()()(())(())(((())))(((()(((())(("
    //     "))(((((())))()()()))))())((()())(";
    // int res = coder32.longestValidParentheses3(s);
    // cout << res << endl;

    // LeeCode33 coder33 = LeeCode33();
    // vector<int> arr{3, 5, 1};
    // int res = coder33.search(arr, 3);
    // cout << res << endl;

    // LeeCode34 coder34 = LeeCode34();
    // vector<int> arr{5,7,7,8,8,10};
    // vector<int> res = coder34.searchRange(arr, 8);
    // cout << res[0] << " " << res[1] << endl;

    // LeeCode35 coder35 = LeeCode35();
    // vector<int> arr{1, 3, 5, 6};
    // int res = coder35.searchInsert(arr, 2);
    // cout << res << endl;

    // LeeCode36 coder36 = LeeCode36();

    // LeeCode38 coder38 = LeeCode38();
    // string res = coder38.countAndSay(4);
    // cout << res << endl;

    // LeeCode40 coder39 = LeeCode40();
    // vector<int> arr{10,1,2,7,6,1,5};
    // vector<vector<int>> res = coder39.combinationSum2(arr, 8);
    // for (int i = 0; i < res.size(); i++) {
    //     printArray(res[i]);
    // }

    // LeeCode41 coder41 = LeeCode41();
    // vector<int> arr{7,8,9,11,12};
    // int res = coder41.firstMissingPositive3(arr);
    // cout << res << endl;

    // LeeCode42 coder42 = LeeCode42();
    // vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // int res = coder42.trap4(arr);
    // cout << res << endl;

    // LeeCode43 coder43 = LeeCode43();
    // string res = coder43.multiply("123", "23");
    // cout << res << endl;

    // LeeCode44 coder44 = LeeCode44();
    // string s = "a";
    // string p = "a*";
    // bool res = coder44.isMatch(s, p);
    // cout << res << endl;

    // LeeCode46 coder46 = LeeCode46();
    // vector<int> arr{1, 2, 3};
    // vector<vector<int>> res = coder46.permute(arr);
    // for (int i = 0; i < res.size(); i++) {
    //     printArray(res[i]);
    // }

    // LeeCode47 coder47 = LeeCode47();
    // vector<int> arr{1, 2, 2, 1, 2};
    // vector<vector<int>> res = coder47.permuteUnique(arr);
    // for (int i = 0; i < res.size(); i++) {
    //     printArray(res[i]);
    // }

    // LeeCode48 coder48 = LeeCode48();
    // vector<vector<int>> arr{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // for (int i = 0; i < arr.size(); i++) {
    //     printArray(arr[i]);
    // }
    // coder48.rotate2(arr);
    // cout << "------------------------" << endl;
    // for (int i = 0; i < arr.size(); i++) {
    //     printArray(arr[i]);
    // }

    // LeeCode49 coder49 = LeeCode49();
    // vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    // // vector<string> strs{"", "b", ""};
    // vector<vector<string>> res = coder49.groupAnagrams(strs);
    // for (int i = 0; i < res.size(); i++) {
    //     for (int j = 0; j < res[i].size(); j++) {
    //         cout << "@@@" + res[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    // LeeCode50 coder50 = LeeCode50();
    // int n = -2147483648;
    // double res = coder50.myPow(1.0, n);
    // cout << res << endl;

    return 0;
};