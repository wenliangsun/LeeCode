#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目134：加油站
 */
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minOil = 0;
        int point = -1;
        int res = 0;
        for (int i = 0; i < gas.size(); i++) {
            res += gas[i] - cost[i];
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