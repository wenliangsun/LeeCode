#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 给定n个数，这n个数两两结合构成一共$n^2$个有序数对（i，
 * j）（可以自己和自己构成有序数对）。 给定k，求第k大的有序数对是哪一个。
 */

typedef long long LL;

int main() {
    int n;
    LL k;
    vector<int> data;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
    sort(data.begin(), data.end());
    LL a = (k - 1) / n;
    LL l = 0, row = 0;
    while (data[l] != data[a]) ++l;
    while (data[l + row] == data[a]) ++row;
    LL aa = (k - 1 - l * n) / row;  // 这个索引牛皮！！！
    printf("(%d,%d)", data[a], data[aa]);
    return 0;
}