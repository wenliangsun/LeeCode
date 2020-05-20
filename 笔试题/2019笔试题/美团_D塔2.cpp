#include <iostream>

using namespace std;

/**
 * 题目链接：https://www.nowcoder.com/practice/fa795cf403f140eabaa023f28318a9b3?tpId=98&tqId=33005&tPage=10&rp=1&ru=%2Fta%2F2019test&qru=%2Fta%2F2019test%2Fquestion-ranking
 */

int main() {
    int T;
    cin >> T;
    while (T--) {
        int s;
        cin >> s;
        int n, d, x, y;
        cin >> n >> d >> x >> y;
        int t0, t1, t2;
        cin >> t0 >> t1 >> t2;
        int t = 0;
        bool can = true;
        while (s > 0) {
            if (t % t0 == 0) {
                s -= n * d;
            }
            if (s <= 0) {
                cout << "NO" << endl;
                can = false;
                break;
            }
            if (t % t1 == 0) {
                s -= y;
            }
            if (t % t2 == 0) {
                s -= x;
            }
            t++;
        }
        if (can) {
            cout << "YES" << endl;
        }
    }
}