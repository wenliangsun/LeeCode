#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 题目和LeeCode上的分发糖果类似，只是这个题是围成一个圈
 *
 * 思路：
 * 规则：如果当前小朋友的得分不左右的高，则需要计算左右的小朋友的糖果，再来得到当前小朋友的糖果数量
 * 所以要计算当前小朋友的糖果数量，需要知道比当前小朋友得分低的小朋友的糖果数量，
 * 所以我们先按照得分排序，然后依次计算每个小朋友获得的糖果数量。
 *
 */

typedef pair<int, int> PII;  // 得分和原来的小朋友的位置
const int N = 1000010;
typedef long long LL;

int n;
int a[N], b[N];  // 得分和分到的糖果
PII children[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            children[i] = {a[i], i};
        }
        // 按得分排序
        sort(children, children + n);
        for (int i = 0; i < n; i++) {
            auto c = children[i];
            // 获取左边和右边的小朋友
            int left = (c.second + n - 1) % n;  // 注意这儿防止越界
            int right = (c.second + 1) % n;
            int lv = 1, rv = 1;
            // 与左边判断得分
            if (c.first > a[left]) lv = b[left] + 1;
            // 与右边判断得分
            if (c.first > a[right]) rv = b[right] + 1;
            // 取两个中的较大者
            b[c.second] = max(lv, rv);
        }
        LL res = 0;
        // 计算总的糖果数量
        for (int i = 0; i < n; i++) {
            res += b[i];
        }
        cout << res << endl;
    }
}
