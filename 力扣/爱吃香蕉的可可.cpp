#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目875：爱吃香蕉的可可
 */
class LeeCode875 {
   public:
    /**
     * 思路：二分法的运用
     * 最小速度是只吃一个，最大速度是吃最大的一堆，然后二分搜索能吃完所有的左边界
     */
    int minEatingSpeed(vector<int>& piles, int H) {
        int minSpeed = 1;                  // 最小速度
        int maxSpeed = getMax(piles) + 1;  // 最大速度
        while (minSpeed < maxSpeed) {      // 二分搜索
            int midSpeed = (minSpeed + maxSpeed) / 2;
            if (canFinished(piles, midSpeed, H)) {
                maxSpeed = midSpeed;
            } else {
                minSpeed = midSpeed + 1;
            }
        }
        return minSpeed;
    }

   private:
    int getMax(vector<int> piles) {
        int mx = INT_MIN;
        for (auto p : piles) {
            if (p > mx) {
                mx = p;
            }
        }
        return mx;
    }
    // 判断当前速度是否能吃完
    bool canFinished(vector<int> piles, int speed, int H) {
        int count = 0;
        for (auto p : piles) {
            // 这儿太秀了！！！
            count += (p / speed) + (p % speed > 0 ? 1 : 0);
        }
        return count <= H;
    }
};

int main() {
    LeeCode875 code = LeeCode875();
    vector<int> nums = {30, 11, 23, 4, 20};
    int res = code.minEatingSpeed(nums, 5);
    cout << res << endl;
}