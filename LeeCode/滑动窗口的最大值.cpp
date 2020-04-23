#include <deque>
#include <vector>

using namespace std;

/**
 * 题目239：滑动窗口的最大值
 */
class LeeCode239 {
   public:
    /**
     * 思路：单调队列
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() == 0 || k <= 0) {
            return res;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {  // 先k-1个入队
                pushNum(nums[i]);
            } else {  // 右移窗口
                pushNum(nums[i]);
                res.push_back(maxNum());
                popNum(nums[i - k + 1]);
            }
        }
        return res;
    }

   private:
    deque<int> data;
    /**
     * 维护一个单调递减的队列
     */
    void pushNum(int n) {
        while (!data.empty() && data.back() < n) {
            data.pop_back();
        }
        data.push_back(n);
    }

    /**
     * 返回最大值
     */
    int maxNum() { return data.front(); }

    /**
     * 删除数
     */
    int popNum(int n) {
        if (!data.empty() && data.front() == n) {
            data.pop_front();
        }
    }
};