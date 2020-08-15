#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int jie[10]; // 记录1-9的阶乘
    jie[0] = 1;
    string nums; // 把1-9的数字转换成字符串
    for (int i = 1; i <= n; i++) {
        jie[i] = jie[i - 1] * i;
        nums += to_string(i);
    }
    k--; // k从1开始
    string res; // 记录答案
    while (nums.size()) {
        int len = nums.size(); // 记录剩余数字的长度
        int idx = k / jie[len - 1]; // 计算第一个位置的数字的索引
        k %= jie[len - 1]; // 剩余的k
        res += nums[idx];
        nums.erase(nums.begin() + idx); // 删除当数字 这一步操作时间复杂度：O(n^2)
    }
    cout << res << endl;
}