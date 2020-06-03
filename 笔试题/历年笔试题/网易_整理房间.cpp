#include <bits/stdc++.h>

using namespace std;

/**
 * 又到了周末，小易的房间乱得一团糟。他希望将地上的杂物稍微整理下，使每团杂物看起来都紧凑一些，没有那么乱。
 * 地上一共有n团杂物，每团杂物都包含4个物品。第i物品的坐标用(ai,bi)表示，小易每次都可以将它绕着(xi,yi)逆时针旋转90∘
 * 这将消耗他的一次移动次数。如果一团杂物的4个点构成了一个面积不为0的正方形，我们说它是紧凑的。
 * 因为小易很懒，所以他希望你帮助他计算一下每团杂物最少需要多少步移动能使它变得紧凑。
 */

const int N = 110;
typedef long long LL;

// n堆杂物，每堆杂物包含4个物品，每个物品包含4个坐标
vector<vector<vector<int>>> a;
int n;

/**
 * 计算两点之间距离的平方
 */
LL dist(vector<int> p1, vector<int> p2) {
    return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
}

/**
 * 判断四个点是否构成正方形
 */
bool isSquare(vector<int> p1, vector<int> p2, vector<int> p3, vector<int> p4) {
    vector<LL> t = {dist(p1, p2), dist(p2, p3), dist(p3, p4),
                    dist(p4, p1), dist(p1, p3), dist(p2, p4)};
    sort(t.begin(), t.end());
    return t[0] != 0 && t[0] == t[1] && t[1] == t[2] && t[2] == t[3] &&
           t[4] == t[5];
}

/**
 * 将一点沿着另一点逆时针旋转90度
 */
vector<int> rotate(vector<int> pos, int cnt) {
    while (cnt--) {
        int x = pos[2] - pos[1] + pos[3];
        int y = pos[3] + pos[0] - pos[2];
        pos[0] = x, pos[1] = y;
    }
    return pos;
}

int main() {
    cin >> n;
    a = vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(4)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) cin >> a[i][j][k];

    for (int idx = 0; idx < n; idx++) {
        int minw = INT_MAX;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    for (int m = 0; m < 4; m++)
                        if (isSquare(rotate(a[idx][0], i), rotate(a[idx][1], j),
                                     rotate(a[idx][2], k),
                                     rotate(a[idx][3], m)))
                            minw = min(minw, i + j + k + m);
        if (minw == INT_MAX)
            cout << -1 << endl;
        else
            cout << minw << endl;
    }
    return 0;
}