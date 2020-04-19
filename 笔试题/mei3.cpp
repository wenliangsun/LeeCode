#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

int main() {
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    LL cnt = 0;
    bool finished = false;
    for (int i = k / a.size(); i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            cnt++;
            if (cnt == k % a.size()) {
                cout << '(' << a[i] << ',' << a[j] << ')' << endl;
                finished = true;
                break;
            }
        }
        if (finished) {
            break;
        }
    }
    return 0;
}