#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 510, M = 510;
int a[N][M];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    unordered_set<int> s;
    for (int j = 0; j < m; j++) {
        vector<PII> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({a[i][j], i});
        }
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        s.insert(temp[0].second);
    }
    cout << s.size() << endl;

    return 0;
}