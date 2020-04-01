
/**
 * 题目50：数组中重复的数字
 * 在一个长度为n的数组里的所有数字都在0到n-1的范围内。
 * 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
 * 请找出数组中任意一个重复的数字。
 * 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
 */
class NewCoder50 {
   public:
    /**
     * 思路：构建一个hash表，来存储每个数字出现的次数，考虑到所有的数字是在0~n-1之间，
     * 所以我们可以使用一个数组来构建hash表。
     *
     * 下面的代码为了节省空间，可以考虑使用bool数组
     */
    bool duplicate(int numbers[], int length, int* duplication) {
        int temp[length];  // 这儿可以替换成bool数组
        // bool temp[length];
        for (int i = 0; i < length; i++) {
            temp[i] = 0;
        }
        for (int i = 0; i < length; i++) {
            temp[numbers[i]]++;
            if (temp[numbers[i]] == 2) {  // 判断当前数字是否已经出现
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};