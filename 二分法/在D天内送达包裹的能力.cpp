#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目1011：在D天内送达包裹的能力
 */
class LeeCode1011 {
   public:
    /**
     * 思路：二分法的运用
     * 一次运货的最小量是包裹的最大量，运货的最大量是所有包裹的总量，然后用二分搜索
     */
    int shipWithinDays(vector<int>& weights, int D) {
        int minWight = getMax(weights);
        int maxWight = getSum(weights) + 1;
        while (minWight < maxWight) {
            int midWight = (minWight + maxWight) / 2;
            // 判断当前运货量能否在规定的期限内完成
            if (canFinished(weights, midWight, D)) {
                maxWight = midWight;
            } else {
                minWight = midWight + 1;
            }
        }
        return minWight;
    }

   private:
    int getMax(vector<int> weights) {
        int mx = INT_MIN;
        for (auto w : weights) {
            if (w > mx) {
                mx = w;
            }
        }
        return mx;
    }

    int getSum(vector<int> weights) {
        int res = 0;
        for (auto w : weights) {
            res += w;
        }
        return res;
    }

    int canFinished(vector<int> weights, int minWight, int D) {
        int count = 0;
        int temp = minWight;
        int index = 0;
        while (index < weights.size()) {
            int w = weights[index];
            temp -= w;
            if (temp < 0) {
                count++;
                temp = minWight;
                if (count >= D) {
                    return false;
                }
            } else {
                index++;
            }
        }
        return true;
    }
};

int main() {
    LeeCode1011 code = LeeCode1011();
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int res = code.shipWithinDays(nums, 5);
    cout << res << endl;
}