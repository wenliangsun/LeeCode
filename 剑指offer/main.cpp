#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <regex>
#include <string>
#include <vector>
#include "NewCoder01.h"
#include "NewCoder02.h"
#include "NewCoder03.h"
#include "NewCoder05.h"
#include "NewCoder06.h"
#include "NewCoder07.h"
#include "NewCoder08.h"
#include "NewCoder09.h"
#include "NewCoder11.h"
#include "NewCoder12.h"
#include "NewCoder13.h"
#include "NewCoder19.h"
#include "NewCoder30.h"
#include "NewCoder33.h"
#include "NewCoder34.h"
#include "NewCoder35.h"
#include "NewCoder37.h"
#include "NewCoder40.h"
#include "NewCoder41.h"
#include "NewCoder42.h"
#include "NewCoder43.h"
#include "NewCoder46.h"
#include "NewCoder49.h"
#include "NewCoder51.h"
#include "NewCoder53.h"
// #include "NewCoder59.h"
// #include "NewCoder60.h"
#include "NewCoder61.h"
// #include "NewCoder62.h"
#include "NewCoder63.h"
#include "NewCoder64.h"
#include "NewCoder65.h"
#include "NewCoder66.h"
#include "NewCoder67.h"
#include "SortAlgorithm.h"

using namespace std;

struct Node {
    int val;
    struct Node *next;

    Node(int x) : val(x), next(NULL) {}

    Node(){

    };
};

void demos();

void testNewCoder05();

void testNewCoder06();

void testNewCoder07();

void testNewCoder08();

void testNewCoder09();

void testNewCoder11();

void testNewCoder12();

void testNewCoder13();

void testNewCoder19();

void shilihuaDemos();

void testNewCoder30();

void testNewCoder33();

void testNewCoder34();

void testNewCoder35();

void testNewCoder37();

void testNewCoder40();

void testNewCoder41();

void testNewCoder42();

void testSortAlgorithm();

void testNewCoder43();

void testNewCoder46();

void testNewCoder49();

void testNewCoder51();

void testNewCoder53();

void testNewCoder59();

void testNewCoder63();

void testNewCoder64();

void testNewCoder65();

void testNewCoder66();

void testNewCoder67();

void printArray(vector<int> array);

int main() {
    // testNewCoder05();
    // testNewCoder06();
    // testNewCoder07();
    // testNewCoder08();
    // testNewCoder09();
    // testNewCoder11();
    // testNewCoder12();
    // testNewCoder13();
    // testNewCoder19();
    // testNewCoder30();
    // testNewCoder33();
    // testNewCoder34();
    // testNewCoder35();
    // testNewCoder37();
    // testNewCoder40();
    // testNewCoder41();
    // testNewCoder42();
    // testSortAlgorithm();
    // testNewCoder43();
    // testNewCoder46();
    // testNewCoder49();
    // testNewCoder51();
    // testNewCoder53();
    // testNewCoder59();
    // testNewCoder63();
    // testNewCoder64();
    // testNewCoder65();
    // testNewCoder66();
    testNewCoder67();

    // int a[]={1, 2, 3, 5, 6};
    // cout<<*a<<endl;
    // bool arr[10];
    // cout << arr[2] << endl;

    // string str;
    // vector<int> vec{1, 2, 3, 4};
    // // char str2[7] = "abcdef";  //最后一个位置保存的'\0'
    // bool b = str[6] == '\0';
    // cout << str.capacity() << endl;
    // cout << "###: " << str[1112] << endl;
    // cout << "***: " << vec[45] << endl;
    // string::iterator s = find(str.begin(), str.end(), 'g');
    // bool bb = s == str.end();
    // cout << bb << endl;
    // //    cout << *s << endl;
    // int f = str.find("aa");
    // cout << f << endl;

    // vector<vector<int>> res{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // cout << res.size() << endl;
    // vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // arr.insert(arr.begin() + 3, 12);
    // printArray(arr);
    // arr.erase(arr.begin() + 6);
    // printArray(arr);

    // list<int> arr{1, 2, 3, 4, 5, 6, 7, 8};
    // for (int i = 0; i < 5; i++) {
    //     arr.push_back(i);
    // }
    // arr.insert(arr.begin(), 10);
    // list<int>::iterator plist;
    // for (plist = arr.begin(); plist != arr.end(); plist++) {
    //     cout << *plist <<" ";
    // }

    // 测试 map
    //    map<char, int> a;
    //    a['a'] = 1;
    //    a['b'] = 2;
    //    bool b = a.find('a') == a.end();
    //    cout << b << endl;
    //    cout << a.at('b') << endl;

    // char str[] = {1,2,3,4};  // 字符数组
    // char *newstr =str;  //
    // 指针变量，里面存的是一个地址，32位系统是4个字节，64位系统是8个字节

    // cout << "字符串的空间长度：" << sizeof(str) << endl;
    // cout << sizeof(str[0]) << endl;
    // cout << sizeof(str) / sizeof(str[0]) << endl;
    // cout << "指针变量的空间：" << sizeof(newstr) << endl;
    // cout << sizeof(newstr[0]) << endl;
    // cout << sizeof(newstr) / sizeof(newstr[0]);

    // char a[] = "hello";
    // char *str = a;
    // str++;
    // cout << *str << endl;

    return 0;
}

void shilihuaDemos() {
    Node node1;
    Node node2(1);
    Node node3 = Node();
    Node node4 = Node(2);
    Node *pNode1 = new Node;
    Node *pNode2 = new Node(3);
    cout << "隐式创建，调用无参构造器 node1 :" << node1.val << endl;
    cout << "隐式创建，调用有参构造器 node2 :" << node2.val << endl;
    cout << "显示创建，调用无参构造器 node3 :" << node3.val << endl;
    cout << "显示创建，调用有参构造器 node4 :" << node4.val << endl;
    cout << "new创建，调用无参构造器 pNode1 :" << pNode1->val << endl;
    cout << "new创建，调用有参构造器 pNode2 :" << pNode2->val << endl;
}

void demos() {
    /*
  string text;
   getline(cin, text);
   cout << text.empty() << endl;
   cin >> text;
  text = "hello world!!!";
  for (auto &c : text) { // c 是引用
      c = toupper(c);
  }
  cout << text << endl;
  */
    //    vector<int> arr(10);
    //    arr.push_back(12);
    //    cout << arr[arr.size() - 1] << endl;

    //    vector<vector<int>> arr = {{1,  2,  3,  4},
    //                               {5,  6,  7,  8},
    //                               {9,  10, 11, 12},
    //                               {13, 14, 15, 16}};
    //    NewCoder01 coder01 = NewCoder01();
    //    bool res = coder01.Find(19, arr);
    //    cout << res << endl;

    //    char str[20] = {'W','e',' ','a','r','e',' ','g','o','o','d','\0'};
    //    cout<< str <<endl;
    //    NewCoder02 coder02 = NewCoder02();
    //    coder02.replaceSpace01(str,12);
    //
    //    NewCoder03 coder03 = NewCoder03();
    //    vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    //    int *p = &arr[0];
    //    int *pend = &arr[arr.size() - 1];
    //    cout << *(++p) << endl;
    //    cout<< str <<endl;
}

void testNewCoder05() {
    NewCoder05 coder05 = NewCoder05();
    for (int i = 0; i < 10; i++) {
        coder05.push(i);
    }
    for (int j = 0; j < 10; ++j) {
        cout << coder05.pop() << endl;
    }
}

void testNewCoder06() {
    vector<int> arr = {4, 4, 4, 5, 6, 7, 8, 9, 1, 2, 2, 3, 3};
    NewCoder06 coder06 = NewCoder06();
    int res = coder06.minNumberInRotateArray02(arr);
    cout << res << endl;
}

void testNewCoder07() {
    NewCoder07 coder07 = NewCoder07();
    cout << coder07.Fibonacci02(10) << endl;
}

void testNewCoder08() {
    NewCoder08 coder08 = NewCoder08();
    cout << coder08.jumpFloor(45) << endl;
}

void testNewCoder09() {
    NewCoder09 coder09 = NewCoder09();
    cout << coder09.jumpFloorII(10) << endl;
}

void testNewCoder11() {
    NewCoder11 coder11 = NewCoder11();
    int num = coder11.numberOf1(10);
    bool power2 = coder11.powerOf2(4);
    int count = coder11.numOfChange(10, 13);
    cout << num << endl;
    cout << power2 << endl;
    cout << count << endl;
}

void testNewCoder12() {
    NewCoder12 coder12 = NewCoder12();
    double res = coder12.power(-1.2, -3);
    cout << res << endl;
}

void testNewCoder13() {
    NewCoder13 coder13 = NewCoder13();
    vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    coder13.reOrderArray02(arr);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << endl;
    }
}

void testNewCoder19() {
    NewCoder19 coder19 = NewCoder19();
    vector<vector<int>> mat{
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<int> res = coder19.printMatrix(mat);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
}

void testNewCoder30() {
    NewCoder30 coder30 = NewCoder30();
    vector<int> arr{1, -2, 3, 10, -4, 7, 2, -5};
    int res = coder30.FindGreatestSumOfSubArray(arr);
    cout << res << endl;
}

void testNewCoder33() {
    NewCoder33 coder33 = NewCoder33();
    int num = coder33.GetUglyNumber_Solution02(1500);
    cout << num << endl;
}

void testNewCoder34() {
    NewCoder34 coder34 = NewCoder34();
    string str = "abcdabxdwx";
    int index = coder34.FirstNotRepeatingChar(str);
    cout << index << endl;
}

void testNewCoder35() {
    NewCoder35 coder35 = NewCoder35();
    vector<int> arr{7, 5, 6, 4};
    int count = coder35.InversePairs(arr);
    cout << count << endl;
}

void testNewCoder37() {
    NewCoder37 coder37 = NewCoder37();
    vector<int> arr{1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4,
                    4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 7};

    int count = coder37.GetNumberOfK01(arr, 1);
    cout << count << endl;
}

void testNewCoder40() {
    NewCoder40 coder40 = NewCoder40();
    vector<int> arr{5, 3, 1, 3, 4, 2, 5, 1, 2, 6};
    //    int res;
    //    coder40.FindNumsAppearOnce(arr, &res);
    //    cout << res << endl;
    int num1, num2;
    coder40.FindNumsAppearOnce01(arr, &num1, &num2);
    cout << num1 << "---" << num2 << endl;
}

void testNewCoder41() {
    NewCoder41 coder41 = NewCoder41();
    vector<vector<int>> res = coder41.FindContinuousSequence(10);
    for (int i = 0; i < res[0].size(); ++i) {
        cout << res[0][i] << endl;
    }
}

void testNewCoder42() {
    NewCoder42 coder42 = NewCoder42();
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> res = coder42.FindNumbersWithSum(arr, 12);
    cout << res[0] << "----" << res[1] << endl;
}

void testSortAlgorithm() {
    SortAlgorithm sa = SortAlgorithm();
    vector<int> arr{1, 7,  5, 3,   42, 21,   2,  3, 43,
                    4, 56, 4, 234, 43, 2123, 34, 13};
    printArray(arr);
    //    vector<int> newArr = sa.BubbleSort(arr);
    vector<int> newArr = sa.QuickSort(arr);
    // printArray(arr);
    printArray(newArr);
}

void testNewCoder43() {
    NewCoder43 coder43 = NewCoder43();
    string str = coder43.LeftRotateString("abcdefgh", 3);
    cout << str << endl;
}

void testNewCoder46() {
    NewCoder46 coder46 = NewCoder46();
    int last = coder46.LastRemaining_Solution02(5, 3);
    cout << last << endl;
}

void testNewCoder49() {
    NewCoder49 coder49 = NewCoder49();
    string str = "+2147483647";
    string str2 = "123";
    int res = coder49.StrToInt(str);
    cout << res << endl;
}

void testNewCoder51() {
    NewCoder51 coder51 = NewCoder51();
    vector<int> arr{1, 2, 3, 4};
    vector<int> res = coder51.multiply(arr);
    printArray(res);
}

void testNewCoder53() { NewCoder53 coder53 = NewCoder53(); }

void testNewCoder59() {
    TreeNode *pHead = new TreeNode(8);
    TreeNode *pNode = pHead;
    pNode->left = new TreeNode(6);
    pNode->right = new TreeNode(10);
    pNode->left->left = new TreeNode(5);
    pNode->left->right = new TreeNode(7);
    pNode->right->left = new TreeNode(9);
    pNode->right->right = new TreeNode(11);

    // NewCoder59 coder59 = NewCoder59();
    // vector<vector<int>> res = coder59.Print(pHead);
    // NewCoder60 coder60 = NewCoder60();
    // vector<vector<int>> res = coder60.Print(pHead);
    NewCoder61 coder61 = NewCoder61();
    char *res = coder61.Serialize(pHead);
    int *p = (int *)res;
    cout << *(++p) << endl;
    // cout << res[0].size() << endl;
    // for (int i = 0; i < res.size(); ++i) {
    //     printArray(res[i]);
    // }
}

void testNewCoder63() {
    NewCoder63 coder63 = NewCoder63();
    coder63.Insert(3);
    coder63.Insert(5);
    coder63.Insert(2);
    coder63.Insert(1);
    coder63.Insert(6);
    coder63.Insert(4);
    coder63.Insert(8);
    coder63.Insert(1);

    double res = coder63.GetMedian();
    cout << res << endl;
}

void testNewCoder64() {
    NewCoder64 coder64 = NewCoder64();
    vector<int> arr{2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> res = coder64.maxInWindows(arr, 4);
    printArray(res);
}

void testNewCoder65() {
    NewCoder65 coder65 = NewCoder65();
    char matrix[] = {'a', 'b', 'c', 'e', 's', 'f',
                     'c', 's', 'a', 'd', 'e', 'e'};
    char str[] = "bcced";
    bool res = coder65.hasPath(matrix, 3, 4, str);
    cout << res << endl;
}

void testNewCoder66() {
    NewCoder66 coder66 = NewCoder66();
    int num = coder66.movingCount(5, 4, 5);
    cout << num << endl;
}

void testNewCoder67() {
    NewCoder67 coder67 = NewCoder67();
    int res = coder67.cutRope03(2);
    cout << res << endl;
}

void printArray(vector<int> array) {
    for (int i = 0; i < array.size(); ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
