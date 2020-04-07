#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目：加油站
 */
class Solution {
   public:
    /**
     * 思路：贪心算法，一次遍历，更新到达站点的最小剩余油量，
     * 则可能的出发点是剩余最小油量站点的下一个站点，即把耗油最大的站点放在最后，
     * 这样就可以使得车在其他站点上加更多的油
     */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minOil = INT_MAX;
        int point = -1;
        int res = 0;
        for (int i = 0; i < gas.size(); i++) {
            // 累计到下一站的剩余油量
            res += gas[i] - cost[i];
            // 更新最小剩余油量
            if (res < minOil) {
                minOil = res;
                point = i;
            }
        }
        return res >= 0 ? point + 1 : -1;
    }
};

int main() {
    Solution s = Solution();
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int res = s.canCompleteCircuit(gas, cost);
    cout << res << endl;
}