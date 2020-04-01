#include <vector>

using namespace std;

/**
 * 题目75：颜色分类
 */
class LeeCode75 {
   public:
    /**
     * 思路：统计每个数字出现的次数，然后重新构造数组
     */
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }
        int times[3];
        for (int i = 0; i < 3; i++) {
            times[i] = 0;
        }
        // 统计每个数字的次数
        for (int i = 0; i < nums.size(); i++) {
            times[nums[i]]++;
        }
        int index = 0;
        // 重新构造数组
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < times[i]; j++) {
                nums[index] = i;
                index++;
            }
        }
    }

    /**
     * 思路：荷兰国旗问题
     * 初始化两个指针分别指向0的右边界和2的左边界，
     * 然后初始化当前指针用于遍历数组，
     * 如果等于0，则和0的右边界交换
     * 如果等于2，则和2的左边界交换
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    void sortColors2(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }
        int index0 = 0;
        int index2 = nums.size() - 1;
        int curIndex = 0;
        while (curIndex <= index2) {
            if (nums[curIndex] == 0) {  // 和0的右边界交换
                int temp = nums[index0];
                nums[index0] = nums[curIndex];
                nums[curIndex] = temp;
                index0++;
                curIndex++;  // 从左到右，和左边交换时，左边的已经判断过了
            } else if (nums[curIndex] == 2) {  // 和2的左边界交换
                int temp = nums[index2];
                nums[index2] = nums[curIndex];
                nums[curIndex] = temp;
                // 注意这儿不能给curIndex加1，因为右边交换过来的数字并没有判断
                index2--;
            } else {
                curIndex++;
            }
        }
    }
};