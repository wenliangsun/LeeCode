#include <bits/stdc++.h>

using namespace std;

/**
 * 将N（N<10000）个人排成一排，从第1个人开始报数；如果报数是M的倍数就出列，报到队尾后则回到队头继续报，直到所有人都出列；
 * 和剑指offer上圆圈中最后剩下的数字差不多一样
 * 使用循环链表，采用模拟法
 */

typedef pair<int, int> PII;

int main() {
    int n, m;
    cin >> n >> m;
    list<PII> nums;
    for (int i = 1; i <= n; i++)
        nums.push_back({i, i});  // 存入双向循环链表 用于模拟
    list<PII>::iterator cur = nums.begin();  // 迭代器
    vector<int> res;                         //记录答案
    while (nums.size()) {                    // 链表非空
        // 寻找下一个出队的位置
        for (int i = 1; i < m; i++) {
            cur++;
            if (cur == nums.end()) cur = nums.begin();
        }
        // 记录下一个位置
        list<PII>::iterator next = ++cur;
        if (next == nums.end()) next = nums.begin();
        --cur;                         // 还原当前位置
        res.push_back((*cur).second);  // 存入答案
        nums.erase(cur);               // 当前位置出队
        cur = next;                    // 移动到下一个位置
    }
    for (auto n : res) cout << n << ' ';
    return 0;
}