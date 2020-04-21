#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * https://www.nowcoder.com/practice/6d9d69e3898f45169a441632b325c7b4?tpId=37&tqId=21247&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking
 *
 * 思路：首先计算每个数在最大递增子序列中的位置
 * 然后计算每个数在反向最大递减子串中的位置
 * 然后将每个数的递增计数和递减计数相加，表示当前位置所在队列中的人数+1.
 */

// 最长递增子序列
void helper(vector<int> h, vector<int>& res) {
    for (int i = 0; i < h.size(); i++) {
        for (int j = i; j >= 0; j--) {
            if (h[j] < h[i]) res[i] = max(res[i], res[j] + 1);
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        vector<int> inNum(n, 1);
        vector<int> decNum(n, 1);
        helper(h, inNum);
        reverse(h.begin(), h.end());
        helper(h, decNum);
        reverse(decNum.begin(), decNum.end());

        int maxNum = 0;
        for (int i = 0; i < n; i++) {
            if (inNum[i] + decNum[i] > maxNum) maxNum = inNum[i] + decNum[i];
        }
        cout << n - maxNum + 1 << endl;
    }
    return 0;
}