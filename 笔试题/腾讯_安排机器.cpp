#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 小Q的公司最近接到m个任务, 第i个任务需要xi的时间去完成, 难度等级为yi。
 * 小Q拥有n台机器, 每台机器最长工作时间zi, 机器等级wi。
 * 对于一个任务,它只能交由一台机器来完成,
 * 如果安排给它的机器的最长工作时间小于任务需要的时间,
 * 则不能完成,如果完成这个任务将获得200 * xi + 3 * yi收益。
 * 对于一台机器,它一天只能完成一个任务,
 * 如果它的机器等级小于安排给它的任务难度等级, 则不能完成。
 * 小Q想在今天尽可能的去完成任务,
 * 即完成的任务数量最大。如果有多种安排方案,小Q还想找到收益最大的那个方案。
 * 小Q需要你来帮助他计算一下。
 *
 * 输入包括N + M + 1行,输入的第一行为两个正整数n和m(1 <= n, m <= 100000), 表示机器的数量和任务的数量。
 * 接下来n行,每行两个整数zi和wi(0 < zi < 1000, 0 <= wi <= 100),表示每台机器的最大工作时间和机器等级。
 * 接下来的m行,每行两个整数xi和yi(0 < xi <1000, 0 <= yi<= 100), 表示每个任务需要的完成时间和任务的难度等级。
 * 
 * 输出两个整数, 分别表示最大能完成的任务数量和获取的收益。
 */

typedef long long LL;
typedef pair<int, int> PII;

int cnt[105]; // 记录时间满足当前任务的所有机器的等级

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<PII> tsk, msh;
        for (int i = 0; i < n; i++) {
            int z, w;
            cin >> z >> w;
            msh.push_back({z, w});
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            tsk.push_back({x, y});
        }
        sort(msh.begin(), msh.end()), reverse(msh.begin(), msh.end());
        sort(tsk.begin(), tsk.end()), reverse(tsk.begin(), tsk.end());
        int num = 0;
        LL res = 0;
        // 遍历每一个任务
        for (int i = 0, j = 0; i < tsk.size(); i++) {
            // 从机器里面寻找所有满足时间要求的机器，注意这儿j每次不是从0开始，是因为排序了
            while (j < n && msh[j].first >= tsk[i].first) {
                cnt[msh[j].second]++; // 类似哈希
                j++;
            }
            // 从小到大遍历所有的等级，找到满足时间要求，且等级最小的机器。
            for (int k = 0; k <= 100; k++) {
                // 第一个是判断是否满足时间要求，第二个是判断是否满足等级要求。
                if (cnt[k] && k >= tsk[i].second) {
                    num++;
                    cnt[k]--;
                    res += 200 * tsk[i].first + 3 * tsk[i].second;
                    break; // 找到了，计算完直接跳出循环。
                }
            }
        }
        cout << num << ' ' << res << endl;
    }
    return 0;
}