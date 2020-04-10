#include <iostream>

using namespace std;

/**
 * 题目：机器人正在玩一个古老的基于DOS的游戏。游戏中有N+1座建筑——从0到N编号，从左到右排列。
 * 编号为0的建筑高度为0个单位，编号为 i
 * 的建筑高度为H(i)个单位。起初，机器人在编号为0的建筑处。
 * 每一步，它跳到下一个（右边）建筑。假设机器人在第k个建筑，且它现在的能量值是E，下一步它将跳到第k+1个建筑。
 * 如果H(k+1)>E，那么机器人就失去H(k+1)-E的能量值，否则它将得到E-H(k+1)的能量值。
 * 游戏目标是到达第N个建筑，在这个过程中能量值不能为负数个单位。
 * 现在的问题是机器人以多少能量值开始游戏，才可以保证成功完成游戏？
 *
 * 思路：二分法  模板
 */

const int N = 100010;

int n;
int a[N];

bool check(int e) {
    for (int i = 0; i < n; i++) {
        e = 2 * e - a[i];
        if (e > N) return true;
        if (e < 0) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 1, r = 1e5;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r << endl;
}