#include <algorithm>
#include <vector>

using namespace std;

/**
 * 题目16：最接近的三数之和
 */
class LeeCode16 {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mindiff = INT_MAX;
        int res = 0;
        sort(nums.begin(), nums.end());  // 排序
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int p1 = i + 1;
                int p2 = nums.size() - 1;
                while (p1 < p2) {
                    // cout << "p1:" << p1 << "---"
                    //      << "p2:" << p2 << endl;
                    int sum = nums[i] + nums[p1] + nums[p2];
                    int diff = sum - target;
                    diff = diff > 0 ? diff : -diff;
                    if (diff < mindiff) {  // 判断差值
                        mindiff = diff;    // 更新最小差值
                        res = sum;         // 更新最近似的结果
                    } else if (sum < target) {
                        p1++;

                    } else {
                        p2--;
                    }
                }
            }
        }
        return res;
    }
};