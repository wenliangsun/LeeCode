#include <iostream>
#include <vector>

using namespace std;
int ans = 0;

void f(int n, vector<int> tmp, int tmps) {
    if (tmps == n) {
        ans += 1;
        return;
    }
    if (tmps > n) return;
    int i;
    if (tmp.size() == 0)
        i = 1;
    else
        i = tmp[tmp.size() - 1];
    for (i; i <= n; i++) {
        tmp.push_back(i);
        f(n, tmp, tmps + i);
        tmp.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> tmp;
    f(n, tmp, 0);
    cout << ans;
    return 0;
}