#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
const int N = 100010;

int n, m;
vector<LL> va(N);

// 超时

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = 0, sum = 0;
        while (r <= n) {
            if (r - l < i) {
                sum += va[r];
                r++;
            } else {
                if (sum % m == 0) {
                    res++;
                }
                sum += va[r];
                sum -= va[l];
                r++;
                l++;
            }
        }
    }

    cout << res << endl;
}