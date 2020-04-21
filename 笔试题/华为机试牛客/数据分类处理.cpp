#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/**
 * https://www.nowcoder.com/practice/9a763ed59c7243bd8ab706b2da52b7fd?tpId=37&tqId=21248&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking
 */

bool isInNum(int a, int b) {
    string as = to_string(a);
    string bs = to_string(b);
    int pos = bs.find(as);
    return pos == bs.npos ? false : true;
}

int main() {
    int m;
    while (cin >> m) {
        vector<int> I(m);
        for (int i = 0; i < m; i++) {
            cin >> I[i];
        }
        int n;
        cin >> n;
        vector<int> R(n);
        for (int i = 0; i < n; i++) {
            cin >> R[i];
        }
        sort(R.begin(), R.end());
        int total = 0;
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            if (i == 0 || (i > 0 && R[i] != R[i - 1])) {
                for (int j = 0; j < m; j++) {
                    if (isInNum(R[i], I[j])) {
                        temp.push_back(j);
                    }
                }
                total += temp.size() == 0 ? 0 : temp.size() * 2 + 2;
            }
            res.push_back(temp);
        }
        cout << total << ' ';
        for (int i = 0; i < n; i++) {
            if (res[i].size() != 0) {
                cout << R[i] << ' ' << res[i].size() << ' ';
                for (int j = 0; j < res[i].size(); j++) {
                    cout << res[i][j] << ' ' << I[res[i][j]] << ' ';
                }
            }
        }
        cout << endl;
    }

    return 0;
}