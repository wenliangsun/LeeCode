#include <algorithm>
#include <vector>

using namespace std;

/**
 * 题目45：扑克牌顺子
 *
 */
class NewCoder45 {
   public:
    /**
     * 思路：对数组进行排序，统计数组中0的个数和gap的数量，
     * 如果0的数量大于等于gaps的数量，则返回true，否则false
     * @param numbers
     */
    bool IsContinuous(vector<int> numbers) {
        if (numbers.empty()) {
            return false;
        }
        int numOfZeros = 0;
        int numOfGaps = 0;
        sort(numbers.begin(), numbers.end());       // 对数组进行排序
        for (int i = 0; i < numbers.size(); i++) {  // 统计0的数量
            if (numbers[i] == 0) {
                numOfZeros++;
            }
        }
        int small = numOfZeros;
        int big = small + 1;
        while (big < numbers.size()) {  // 统计gap的数量
            if (numbers[small] == numbers[big]) {
                return false;
            }
            numOfGaps += numbers[big] - numbers[small] - 1;
            small = big;
            big++;
        }
        return numOfZeros >= numOfGaps ? true : false;
    }
};