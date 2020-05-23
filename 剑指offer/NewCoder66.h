
/**
 * 题目66：机器人的运动范围
 *
 */
class NewCoder66 {
   public:
    int movingCount(int threshold, int rows, int cols) {
        bool visited[rows * cols]; // 标志数组
        for (int i = 0; i < rows * cols; i++) {
            visited[i] = false;
        }
        return canMoving(threshold, 0, rows, 0, cols, visited);
    }

   private:
    int canMoving(int threshold, int x, int rows, int y, int cols,
                  bool* visited) {
        int count = 0;
        int index = x * cols + y;
        // 不满足的情况，直接返回0
        if (x < 0 || y < 0 || x >= rows || y >= cols ||
            visited[index] == true || (sumDigit(x) + sumDigit(y)) > threshold) {
            return 0;
        }
        // 当前格子符合要求
        visited[index] = true; // 标记为已记录
        // 判断上下左右是否符合
        return 1 + canMoving(threshold, x - 1, rows, y, cols, visited) +
               canMoving(threshold, x, rows, y - 1, cols, visited) +
               canMoving(threshold, x + 1, rows, y, cols, visited) +
               canMoving(threshold, x, rows, y + 1, cols, visited);
    }

    int sumDigit(int num) {
        int res = 0;
        while (num) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
};