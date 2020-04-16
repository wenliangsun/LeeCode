#include <deque>
#include <iostream>

using namespace std;

typedef long long LL;

int add(deque<LL> q) {
    int sum = 0;
    while (!q.empty()) {
        sum += q.front();
        q.pop_front();
    }
    return sum;
}

int main() {
    int k;
    LL n;
    cin >> k >> n;
    if (n < k) {
        cout << 1 % 397 << endl;
    } else {
        LL sum = k;
        deque<LL> q;
        for (int i = 0; i < k; i++) {
            q.push_back(1);
        }
        q.push_back(sum);
        for (int i = k + 1; i < n; i++) {
            sum = add(q);
            q.pop_front();
            q.push_back(sum);
        }
        cout << sum % 397 << endl;
    }
}