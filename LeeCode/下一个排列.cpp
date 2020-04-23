#include <vector>

using namespace std;

class LeeCode31 {
   public:
    void nextPermutation(vector<int>& nums) {
        bool flag = true;  // 是最大排列
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {  // 如果是最大排列则翻转一下
            int p1 = 0;
            int p2 = nums.size() - 1;
            while (p1 < p2) {
                int temp = nums[p1];
                nums[p1] = nums[p2];
                nums[p2] = temp;
                p1++;
                p2--;
            }
        } else {
            for (int i = nums.size() - 1; i > 0; i--) {
                // 从后往前，如果当前值大于它前面的值，则对数组从当前位置到末尾排序
                if (nums[i] > nums[i - 1]) {
                    sort(nums.begin() + i, nums.end());
                    // 然后遍历后面排序后的数组，依次与当前位置的前一个数比较，若大于，则交换，得到结果
                    for (int j = i; j < nums.size(); j++) {
                        if (nums[i - 1] < nums[j]) {
                            int temp = nums[i - 1];
                            nums[i - 1] = nums[j];
                            nums[j] = temp;
                            return;
                        }
                    }
                }
            }
        }
    }
};