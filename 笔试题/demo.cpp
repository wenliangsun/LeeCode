#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<double, pair<int, int>> PII;
const int M = 510;

int a[M][M];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, len;
        cin >> m >> len;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int x, y;
        cin >> x >> y;
        vector<PII> dist;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                double d = sqrt((i - x) * (i - x) + (j - y) * (j - y));
                dist.push_back({d, {i, j}});
            }
        }
        sort(dist.begin(), dist.end());
        for (int i = 1; i < dist.size(); i++) {
            auto t = dist[i];
            double d = t.first;
            int t_x = t.second.first, t_y = t.second.second;
            if (len >= d) {
                if (a[t_x][t_y] != 0) {
                    len += a[t_x][t_y];
                }
            }
        }
        cout << len << endl;
    }

    return 0;
}