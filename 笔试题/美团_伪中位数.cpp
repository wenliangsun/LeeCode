#include <iostream>

using namespace std;

/**
 * 给定有序数列伪中位数的定义，m=a[floor((n-1)/2)]，
 * 其实就是当n为奇数时就是正常中位数，n是偶数时取中间两个数较小的那个数。
 * 给定一个数列，和一个值k，问至少添加几个数，使得该序列的伪中位数等于k。
 */

const int N = 510;

int n, k;

int main() {
    cin >> n >> k;
    int cnt_big = 0, cnt_equal = 0, cnt_small = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t < k)
            cnt_small++;
        else if (t == k)
            cnt_equal++;
        else
            cnt_big++;
    }
    int res =
        max(0, max(cnt_small - cnt_big + 1, cnt_big - cnt_small) - cnt_equal);
    cout << res << endl;
    return 0;
}