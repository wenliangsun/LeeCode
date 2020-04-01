#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "LeeCode54.h"
#include "LeeCode56.h"
#include "LeeCode57.h"
#include "LeeCode58.h"
#include "LeeCode59.h"
#include "LeeCode60.h"
#include "LeeCode62.h"
#include "LeeCode63.h"
#include "LeeCode64.h"
#include "LeeCode65.h"
#include "LeeCode66.h"
#include "LeeCode67.h"
#include "LeeCode69.h"
#include "LeeCode70.h"
#include "LeeCode71.h"
#include "LeeCode72.h"
#include "LeeCode73.h"
#include "LeeCode74.h"
#include "LeeCode75.h"
#include "LeeCode76.h"
#include "LeeCode77.h"
#include "LeeCode78.h"
#include "LeeCode79.h"
#include "LeeCode80.h"
#include "LeeCode81.h"
#include "LeeCode84.h"
#include "LeeCode85.h"
#include "LeeCode87.h"
#include "LeeCode89.h"
#include "LeeCode90.h"
#include "LeeCode91.h"
#include "TreeNode.h"

using namespace std;

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main() {
    // vector<vector<int>> arr{
    //     {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // LeeCode54 coder54 = LeeCode54();
    // vector<int> res = coder54.spiralOrder(arr);
    // printArray(res);

    // LeeCode56 coder56 = LeeCode56();
    // // vector<vector<int>> inter = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> inter = {{1, 4}, {4, 5}};
    // vector<vector<int>> res = coder56.merge(inter);
    // for (int i = 0; i < res.size(); i++) {
    //     printArray(res[i]);
    // }

    // LeeCode57 coder57 = LeeCode57();
    // vector<vector<int>> inter = {{1, 5}};
    // vector<int> newarr = {2, 7};
    // vector<vector<int>> res = coder57.insert(inter, newarr);
    // for (int i = 0; i < res.size(); i++) {
    //     printArray(res[i]);
    // }

    // LeeCode58 coder58 = LeeCode58();
    // string s = "Hello a am ok!   ";
    // int res = coder58.lengthOfLastWord(s);
    // cout << res << endl;

    // LeeCode59 coder59 = LeeCode59();
    // vector<vector<int>> res = coder59.generateMatrix(3);
    // for (int i = 0; i < res.size(); i++) {
    //     printArray(res[i]);
    // }

    // LeeCode60 coder60 = LeeCode60();
    // string res = coder60.getPermutation(4, 9);
    // cout << res << endl;

    // LeeCode62 coder62 = LeeCode62();
    // int res = coder62.uniquePaths2(3, 3);
    // cout << res << endl;

    // LeeCode63 coder63 = LeeCode63();
    // vector<vector<int>> arr = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    // int res = coder63.uniquePathsWithObstacles2(arr);
    // cout << res << endl;

    // LeeCode64 coder64 = LeeCode64();
    // vector<vector<int>> arr = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    // int res = coder64.minPathSum(arr);
    // cout << res << endl;

    // LeeCode65 coder65 = LeeCode65();
    // string s = "   2.";
    // bool res = coder65.isNumber(s);
    // cout << res << endl;

    // LeeCode66 coder66 = LeeCode66();
    // vector<int> arr = {3, 2, 3};
    // vector<int> res = coder66.plusOne2(arr);
    // printArray(res);

    // LeeCode67 coder67 = LeeCode67();
    // string a = "11";
    // string b = "1";
    // string res = coder67.addBinary(a, b);
    // cout << res << endl;

    // LeeCode69 coder69 = LeeCode69();
    // int res = coder69.mySqrt2(8);
    // cout << res << endl;

    // LeeCode70 coder70 = LeeCode70();
    // int res = coder70.climbStairs3(3);
    // cout << res << endl;

    // LeeCode71 coder71 = LeeCode71();
    // string path = "/////";
    // string res = coder71.simplifyPath(path);
    // cout << res << endl;

    // LeeCode72 coder72 = LeeCode72();
    // string s1 = "intention";
    // string s2 = "execution";
    // int res = coder72.minDistance2(s1, s2);
    // cout << res << endl;

    // LeeCode73 coder73 = LeeCode73();
    // vector<vector<int>> mat = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    // coder73.setZeroes2(mat);
    // for (int i = 0; i < mat.size(); i++) {
    //     printArray(mat[i]);
    // }

    // LeeCode74 coder74 = LeeCode74();
    // vector<vector<int>> mat = {
    //     {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    // bool res = coder74.searchMatrix2(mat, 3);
    // cout << res << endl;

    // LeeCode75 coder75 = LeeCode75();
    // vector<int> nums = {1,2,0};
    // coder75.sortColors2(nums);
    // printArray(nums);

    // LeeCode76 coder76 = LeeCode76();
    // string s = "ADOBECODEBANC";
    // string t = "ABC";
    // string res = coder76.minWindow(s, t);
    // cout << res << endl;

    // LeeCode77 coder77 = LeeCode77();
    // vector<vector<int>> res = coder77.combine(4, 2);
    // for (int i = 0; i < res.size(); i++) {
    //     printArray(res[i]);
    // }

    // LeeCode78 coder78 = LeeCode78();
    // vector<int> nums = {1, 2, 3};
    // vector<vector<int>> res = coder78.subsets(nums);
    // cout << res.size() << endl;
    // for (int i = 0; i < res.size(); i++) {
    //     printArray(res[i]);
    // }

    // LeeCode79 coder79 = LeeCode79();
    // vector<vector<char>> board = {
    //     {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // string s = "ABCCED";
    // bool res = coder79.exist(board, s);
    // cout << res << endl;

    // LeeCode80 coder80 = LeeCode80();
    // vector<int> nums = {0,0,1,1,1,1,2,3,3};
    // int res = coder80.removeDuplicates(nums);
    // cout<<res<<endl;
    // printArray(nums);

    // LeeCode81 coder81 = LeeCode81();
    // vector<int> nums = {1, 1, 3, 1};
    // bool res = coder81.search(nums, 1);
    // cout << res << endl;

    // LeeCode84 coder84 = LeeCode84();
    // vector<int> heights = {2, 1, 2};
    // int res = coder84.largestRectangleArea4(heights);
    // cout << res << endl;

    // LeeCode85 coder85 = LeeCode85();
    // vector<vector<char>> mat = {{'1', '0', '1', '0', '0'},
    //                             {'1', '0', '1', '1', '1'},
    //                             {'1', '1', '1', '1', '1'},
    //                             {'1', '0', '0', '1', '0'}};
    // int res = coder85.maximalRectangle(mat);
    // cout << res << endl;

    // LeeCode87 coder87 = LeeCode87();
    // string s1 = "great";
    // string s2 = "rgeat";
    // bool res = coder87.isScramble(s1, s2);
    // cout << res << endl;

    // LeeCode89 coder89 = LeeCode89();
    // vector<int> res = coder89.grayCode(2);
    // printArray(res);

    // LeeCode90 coder90 = LeeCode90();
    // vector<int> nums = {1, 2, 2};
    // vector<vector<int>> res = coder90.subsetsWithDup(nums);
    // for (int i = 0; i < res.size(); i++) {
    //     printArray(res[i]);
    // }

    // LeeCode91 coder91 = LeeCode91();
    // string s = "012";
    // int res = coder91.numDecodings(s);
    // cout << res << endl;

    return 0;
}
