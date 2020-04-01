#include <string>
#include <vector>

using namespace std;

/**
 * 题目60：第K个排列
 */
class LeeCode60 {
   public:
    /**
     * 思路：回溯法 递归求解
     */
    string getPermutation(int n, int k) {
        string nums = "";
        bool used[n];
        for (int i = 1; i <= n; i++) {
            nums += to_string(i);
            used[i - 1] = false;
        }
        string s;
        permute(nums, 0, k, s, used);
        return res;
    }

   private:
    int times = 0;
    string res;
    void permute(string nums, int begin, int k, string s, bool* used) {
        if (begin == nums.size()) {
            times++;
            if (times == k) {
                res = s;
            }
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // 这儿进行剪枝，条件有两个
            if (!used[i] && times < k) {
                s.push_back(nums[i]);
                used[i] = true;
                permute(nums, begin + 1, k, s, used);
                s.pop_back();
                used[i] = false;
            }
        }
    }
};