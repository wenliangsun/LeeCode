#include <iostream>
#include <vector>

using namespace std;

/**
 * 给n个学生的m科成绩，如果一个学生的某一科是单科最高，那么这个学生获得奖励，
 * 即便该学生有多科最高，也只获得一次奖励。求获得奖励的学生人数。
 */

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> data(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp;
            cin >> tmp;
            data[i].push_back(tmp);
        }
    }
    vector<int> flag(n); // 用于标记获得奖励的学生
    for (int j = 0; j < m; ++j) {
        int max_value = 0;
        vector<int> max_index; // 用来存最大值对应的同学的索引
        for (int i = 0; i < n; ++i) {
            if (data[i][j] > max_value) {
                max_value = data[i][j];
                max_index.clear();
                max_index.push_back(i);
            } else if (data[i][j] == max_value) {
                max_index.push_back(i);
            }
        }
        // 将当前科最大值的同学打上标记
        for (int i = 0; i < max_index.size(); ++i) {
            flag[max_index[i]] = 1;
        }
    }
    int ans = 0;
    // 统计结果
    for (int i = 0; i < n; ++i) {
        ans += flag[i];
    }
    cout << ans << endl;
    return 0;
}
