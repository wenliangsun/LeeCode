#include <bits/stdc++.h>

using namespace std;

/**
 * 连通区域（Connected
 * Component）一般是指图像中具有相同像素值且位置相邻的像素点组成的图像区域。每个像素点有8个邻接点，包括了上下左右和对角线的像素点。如果点a与b邻接，称之为a与b连通。如果域A与B连通，B与C连通，则A与C也连通。
 * 试找出一个二值矩阵的所有连通域（8邻接），并给出每个连通域的面积（邻接点的个数）和重心。
 * https://www.nowcoder.com/question/next?pid=21366709&qid=839080&tid=34402517
 * 
 * 深搜
 */

typedef pair<int, int> PII;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int m, n;
vector<int> area;         // 记录面积
int cnt;                  // 统计当前区域的面积
vector<vector<PII>> pos;  // 记录区域中所有的位置
vector<PII> tmp;          // 记录当前区域中的位置

/**
 * dfs寻找连通区域
 */
void dfs(vector<vector<int>>& a, int x, int y) {
    cnt++;
    tmp.push_back({x, y});
    a[x][y] = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny]) {
            dfs(a, nx, ny);
        }
    }
}

int main() {
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {  // 从1的位置开始dfs
                cnt = 0;         // 计数清零
                tmp.clear();     // 位置清空
                dfs(a, i, j);
                area.push_back(cnt);
                pos.push_back(tmp);
            }
        }
    }
    vector<pair<double, double>> res;
    for (int i = 0; i < pos.size(); i++) {
        unordered_map<int, int> hashx, hashy;  // 统计每个位置出现的次数
        for (auto item : pos[i]) {
            hashx[item.first]++;   // x轴上出现的次数
            hashy[item.second]++;  // y轴上出现的次数
        }
        double sx = 0, sy = 0;
        for (auto item : hashx) sx += item.first * item.second;  // 加权和
        for (auto item : hashy) sy += item.first * item.second;  // 加权和
        res.push_back({sx / area[i], sy / area[i]});  // 记录重心的坐标
    }
    cout << area.size() << endl;
    for (int i = 0; i < area.size(); i++) {
        printf("%d %.2f %.2f\n", area[i], res[i].second, res[i].first);
    }
    return 0;
}