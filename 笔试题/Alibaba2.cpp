#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * 题目描述：有n头鹿，m只箭，每头鹿都有一定的血量，每只箭也有相应的伤害值，
 * 使用每只箭都有相应的花费，当箭的伤害值大于等于鹿的血量时，可以将其射死，
 * 问如果能将所有鹿射死，求需要的最少花费是多少，如果不能全部射死，就输出NO
 * 1
 * 3 3
 * 1 2 3
 * 2 3 4
 * 1 2 3
 * 6
 *
 * 思路：将鹿按血量排序，定义一个箭的结构体，包含伤害值和花费两个属性，将箭按照伤害值排序，
 * 然后对每只鹿，用能将其射死且花费最小的箭射它，这儿用到按花费排序的优先队列。
 */

struct Arrow {
    int damage;
    int cost;
    Arrow(int x, int y) : damage(x), cost(y) {}
};

struct cmp {
    bool operator()(Arrow* a1, Arrow* a2) { return a1->cost > a2->cost; }
};

bool static compare(Arrow* a1, Arrow* a2) { return a1->damage < a2->damage; }

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        vector<int> nums(N, 0);
        vector<Arrow*> arrows;
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        vector<int> damage(M, 0);
        for (int i = 0; i < M; i++) {
            cin >> damage[i];
        }
        vector<int> cost(M, 0);
        for (int i = 0; i < M; i++) {
            cin >> cost[i];
        }
        for (int i = 0; i < M; i++) {
            Arrow* arrow = new Arrow(damage[i], cost[i]);
            arrows.push_back(arrow);
        }

        if (N > M) {
            cout << "NO";
        } else {
            // 定义优先队列 用于按花费大小存储伤害值高于血量的箭
            priority_queue<Arrow*, vector<Arrow*>, cmp> q;
            int res = 0;                                  // 记录结果
            bool can = true;                              // 能否全部射死
            sort(nums.begin(), nums.end());               // 按血量排序
            sort(arrows.begin(), arrows.end(), compare);  // 按伤害值排序

            int j = M - 1;
            for (int i = N - 1; i >= 0; i--) {
                // 将能射死当前鹿的箭入优先队列
                while (j >= 0 && arrows[j]->damage >= nums[i]) {
                    q.push(arrows[j]);
                    j--;
                }
                // 如果没有能射死当前鹿的箭，则不能全部射死
                if (q.size() == 0) {
                    cout << "NO";
                    can = false;
                    break;
                    //否则拿出花费最小的箭射死当前鹿
                } else {
                    Arrow* arrow = q.top();
                    q.pop();
                    res += arrow->cost;
                }
            }
            if (can) {
                cout << "Total cost: " << res;
            }
        }
    }
}