#include <vector>

using namespace std;

/**
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 请找出其中最小的元素。
 * 你可以假设数组中不存在重复元素。
 */

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] <= nums.back())
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }

    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            // 可以处理 [1,3,3] 和 [3,1,3] 这种情况
            if(numbers[mid] < numbers[r])r = mid;
            else if(numbers[mid]>numbers[r])l = mid + 1;
            else r--;
        }
        return numbers[l];
    }
};