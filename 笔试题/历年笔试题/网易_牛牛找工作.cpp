#include <bits/stdc++.h>

using namespace std;

/**
 * 为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。
 * 牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。
 * 在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。
 * 牛牛的小伙伴太多了，于是他只好把这个任务交给了你。
 * 
 * 算法时间复杂度要求：O(nlogn) 排序算法
 */

const int N = 100010, M = N;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<PII> jobs;
        for (int i = 0; i < n; i++) {
            int d, p;
            cin >> d >> p;
            jobs.push_back({d, p});
        }
        vector<PII> p;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            p.push_back({a, i});
        }
        // 按工作的难易程度排序
        sort(jobs.begin(), jobs.end());
        // 按伙伴的能力排序
        sort(p.begin(), p.end());
        int mx = 0;
        // 更新当前能力下，可以获得的最大报酬
        for (int i = 0; i < n; i++) {
            mx = max(mx, jobs[i].second);
            jobs[i].second = mx;
        }
        int pIdx = 0, jIdx = 0;
        vector<int> res(m);
        // 遍历每一个伙伴和工作，如果当前伙伴的能力大于当前工作，则换下一个工作，否则当前伙伴只能获得当前的工作的报酬
        while (pIdx < m && jIdx < n) {
            if (p[pIdx].first >= jobs[jIdx].first)
                jIdx++;
            else {
                // 注意这儿的操作  前一位
                res[p[pIdx].second] = jobs[jIdx - 1].second;
                pIdx++;
            }
        }
        // 确保所有的伙伴都找到工作
        while (pIdx < m) res[p[pIdx++].second] = jobs[n - 1].second;
        for (int i = 0; i < m; i++) {
            cout << res[i] << endl;
        }
    }
    return 0;
}