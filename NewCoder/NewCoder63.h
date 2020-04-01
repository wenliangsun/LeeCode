#include <vector>

using namespace std;

/**
 * 题目63：数据流中的中位数
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
 * 那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
 * 那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，
 * 使用GetMedian()方法获取当前读取数据的中位数。
 *
 */
class NewCoder63 {
   public:
    void Insert(int num) {
        res.push_back(num);
        for (int i = res.size() - 1; i > 0; i--) {
            if (res[i] < res[i - 1]) {
                int temp = res[i];
                res[i] = res[i - 1];
                res[i - 1] = temp;
            }
        }
    }
    double GetMedian() {
        int len = res.size();
        if (len % 2 == 0) {
            return (res[len / 2 - 1] + res[len / 2]) / 2.;
        } else {
            return res[len / 2];
        }
    }

   private:
    vector<int> res;
};