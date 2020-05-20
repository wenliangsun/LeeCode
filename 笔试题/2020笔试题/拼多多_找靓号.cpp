#include <bits/stdc++.h>

using namespace std;

/**
 * 给定字符串长度为N，字符串只会包括'0'-'9'，
 * 要求修改字符串使得至少有一个字符出现K次，
 * 修改每个字符的代价为对应数字的变化大小，求最小代价，
 * 并输出最小代价下的最小字符串。
 * 
 * 暴力 + 贪心
 * 
 */

const int N = 10010;

// 定义每个数字的结点
struct Node {
    int cost;    //记录保存当前值转换为目标值的花费
    int idx;     // 记录当前数字在字符串中的位置
    int target;  // 记录要转换的目标值
    int ori;     // 记录原始的数字
};

int nums[N];  // 保存将字符串转为数组
Node nds[N];  // 记录每个数字的信息
int res[N];   // 记录答案
int n, k;

// 先按照花费大小进行排序，如果花费一样，如果当前数比目标数小的，则优先处理后面的数
bool cmp(Node nd1, Node nd2) {
    if (nd1.cost != nd2.cost) return nd1.cost < nd2.cost;
    if (nd1.idx < nd2.idx) return nd1.target < nd1.ori;
    return nd2.target > nd2.ori;
}

int main() {
    while (cin >> n >> k) {
        string s;
        cin >> s;
        // 转换成数字
        for (int i = 0; i < s.size(); i++) {
            nums[i] = s[i] - '0';
        }
        int cnt = INT_MAX, tmp;  // cnt 记录最小花费
        // 暴力尝试每一个数字0-9作为相同的数字
        for (int i = 0; i <= 9; i++) {
            // 遍历所有数字，计算花费
            for (int j = 0; j < n; j++) {
                nds[j].cost = abs(nums[j] - i);
                nds[j].idx = j;
                nds[j].target = i;
                nds[j].ori = nums[j];
            }
            // 按照排序规则排序
            sort(nds, nds + n, cmp);
            tmp = 0;
            // 计算当使i作为相同数字时的花费
            for (int j = 0; j < k; j++) tmp += nds[j].cost;
            // 如果比之前的花费小，则更新花费和答案数组
            if (tmp < cnt) {
                cnt = tmp;
                // 先将原来的数字拷贝一份
                for (int j = 0; j < n; j++) res[j] = nums[j];
                // 再将需要修改的地方进行修改
                for (int j = 0; j < k; j++) res[nds[j].idx] = i;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}