#include <algorithm>
#include <iostream>

using namespace std;

const int N = 510;

int a[N];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    int midV = n % 2 == 0 ? (a[n / 2] + a[n / 2 - 1]) / 2 : a[n / 2];
    if (midV == k) {
        cout << 0 << endl;
    } else {
        int len = n;
        int count = 0;
        int midIdx = len / 2;
        while (midIdx >= 0 && midIdx < n) {
            if (len % 2 == 0) {
                midV = (a[len / 2] + a[len / 2 - 1]) / 2;
                if (midV < k) {
                    len++;
                    midIdx++;
                    count++;
                } else if (midV > k) {
                    len++;
                    midIdx--;
                    count++;
                } else {
                    cout << count << endl;
                    break;
                }
            } else {
                midV = a[len / 2];
                if (midV < k) {
                    len++;
                    midIdx++;
                    count++;
                } else if (midV > k) {
                    len++;
                    midIdx--;
                    count++;
                } else {
                    cout << count << endl;
                    break;
                }
            }
        }
        cout << k << endl;
    }

    return 0;
}