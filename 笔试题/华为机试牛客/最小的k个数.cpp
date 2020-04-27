#include <iostream>
#include <queue>

using namespace std;

/**
 * 输入n个整数，输出其中最小的k个。
 */

int main() {
    int n, k;
    while (cin >> n >> k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pq.push(x);
        }
        for (int i = 0; i < k; i++) {
            auto t = pq.top();
            pq.pop();
            cout << t << ' ';
        }
        cout << endl;
    }
    return 0;
}
