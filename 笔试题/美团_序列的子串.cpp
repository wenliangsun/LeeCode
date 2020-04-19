#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
 * 序列中任意个连续的元素组成的子序列称为该序列的子串。
 * 现在给你一个序列P和一个整数K，询问元素和是K的倍数的子串的最大长度。
 * 比如序列【1,2,3,4,5】，给定的整数K为
 * 5，其中满足条件的子串为{5}、{2,3}、{1,2,3,4}、{1,2,3,4,5}， 那么答案就为
 * 5，因为最长的子串为{1,2,3,4,5}；如果满足条件的子串不存在，就输出 0。
 *
 *
 * 思路：数据量是10^5,O(n^2)肯定会超时，
 * 考虑用一个sum(n+1)的值来保存从1-k之间的所有和，由于害怕超出数组的长度，
 * 最后我保存sum之前，全部对k进行取余操作，这对于原题目是一样的；
 * 在sum（0）插入一个0，然后比较sum字符串相同的最远的i，j差值；
 */

const int N = 100010;
int n, k;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    vector<int> sum(n + 1);
    int total = 0;
    for (int i = 1; i <= n; i++) {
        // 计算前缀和
        total += a[i - 1];
        // 保存前缀和的余数
        sum[i] = total % k;
    }
    int len = 0;
    //有id=0的情况，需要对id+1处理
    map<int, int> count;  // 记录第一次余数出现的地方
    for (int i = 0; i <= n; i++) {
        int zhi = sum[i];
        if (count[zhi] == 0) {
            count[zhi] = i + 1;
            continue;
        } else {
            // 下一次余数与之前余数相同时，下一次的和减去前一次的和就是k的倍数，
            // 此时区间长度就是序列的长度
            int curlen = i + 1 - count[zhi];
            len = max(len, curlen);
        }
    }
    cout << len << endl;
    return 0;
}