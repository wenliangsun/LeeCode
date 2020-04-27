#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
 * 小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，相差最小的有多少对呢？相差最大呢？
 */

const int N = 100010;

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        map<int, int> small;
        for (int i = 0; i < n - 1; i++) {
            small[a[i + 1] - a[i]]++;
        }
        int cnt1 = 1, cnt2 = 1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1])
                cnt1++;
            else
                break;
        }
        for (int i = n - 1; i > 0; i--) {
            if (a[i] == a[i - 1])
                cnt2++;
            else
                break;
        }
        map<int, int, greater<int>>::iterator it;
        it = small.begin();
        auto t = *it;
        int mincnt = 0;
        // 考虑全是相同的情况
        if (t.first == 0) {
            for (int i = 1; i < n; i++) {
                int j = i - 1;
                while (j >= 0 && a[j] == a[i]) {
                    mincnt++;
                    j--;
                }
            }
        } else {
            mincnt = t.second;
        }
        cout << mincnt << ' ' << cnt1 * cnt2 << endl;
    }
    return 0;
}