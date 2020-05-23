#include <algorithm>
#include <map>
#include <vector>

using namespace std;

/**
 * 题目41：缺失的第一个正数
 */
class LeeCode41 {
   public:
    /**
     * 思路：利用排序数组来做
     */
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // 先对数组进行排序
        int temp = 0;                    // 从0开始逐渐递增
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {  // 从正数开始
                if (i == 0) {   // 保证对第一个数递增
                    temp++;
                    // 对不重复的数递增
                } else if (i > 0 && nums[i] != nums[i - 1]) {
                    temp++;
                }
                // 判断当前数和递增数是否相等，若不相等，说明数组中缺乏该数字直接返回
                if (nums[i] != temp) {
                    return temp;
                }
            }
        }
        return temp + 1;
    }

    /**
     * 思路：哈希表法
     * 空间复杂度不符合要求
     * 利用hash表把数组中的元素保存，然后从1开始递增，依次判断hash表中是否包含该数字
     * 如果不包含，则返回该数字。否则为该数组长度+1.
     */
    int firstMissingPositive2(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = nums[i];
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (m.find(m[i]) == m.end()) {
                return i;
            }
        }
        return nums.size() + 1;
    }

    /**
     * 思路：将数组视为哈希表
     * 要找的数在[1,N+1]闭区间，但是我们对于N+1这个数不需要找，因为当前面没找到时，则返回N+1
     * (1) 把数组遍历一遍，把1放在0的位置，依次存放；
     * (2) 再遍历一次数组，第一个元素不等于下标的那个数，就是我们确实的正数。
     */
    int firstMissingPositive3(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            // while如果当前的位置不是正确的数字，则一直循环直至当前位置数字是合适的数字
            // 当前位置的数字不在[1,N+1]区间
            while (nums[i] > 0 && nums[i] <= nums.size() &&
                   nums[nums[i] - 1] != nums[i]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};