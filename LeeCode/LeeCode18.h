#include <algorithm>
#include <vector>

using namespace std;

/**
 * 题目18：四数之和
 */
class LeeCode18 {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                for (int j = i + 1; j < nums.size() - 2; j++) {
                    if (j == i + 1 || (nums[j] != nums[j - 1])) {
                        int p1 = j + 1;
                        int p2 = nums.size() - 1;
                        while (p1 < p2) {
                            int sum = nums[p1] + nums[p2] + nums[i] + nums[j];
                            if (sum < target) {
                                p1++;
                            } else if (sum == target) {
                                if (p1 == j + 1 || nums[p1] != nums[p1 - 1]) {
                                    vector<int> temp{nums[i], nums[j], nums[p1],
                                                     nums[p2]};
                                    res.push_back(temp);
                                }
                                p1++;
                                p2--;
                            } else {
                                p2--;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};