
/**
 * 题目65：矩阵中的路径
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
 * 如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
 */
class NewCoder65 {
   public:
    /**
     * 注意：数组指针参数！！！
     */
    bool hasPath(char* matrix, int rows, int cols, char* str) {
        // 用于标记数组中的位置是否被访问过
        bool visited[rows * cols] = {0};
        // 在数组中寻找字符串的第一个字符
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (hasPathCore(matrix, i, rows, j, cols, visited, str)) {
                    return true;
                }
            }
        }

        return false;
    }

   private:
    bool hasPathCore(char* matrix, int x, int rows, int y, int cols,
                     bool* visited, char* str) {
        if (*str == '\0') {  // 如果字符串结束了，则返回true
            return true;
        }
        // cout << *str << "@ visited：";
        // for (int i = 0; i < rows * cols; i++) {
        //     cout << visited[i] << "---";
        // }
        // cout << endl;

        int index = x * cols + y;  // 计算字符在数组中的索引
        if (x < 0 || y < 0 || x >= rows || y >= cols || matrix[index] != *str ||
            visited[index] == true) {
            return false;
        }
        visited[index] = true;  // 标记当前位置访问过了
        str++;                  // 匹配字符串中的下一个字符
        // 匹配上下左右四个位置
        if (hasPathCore(matrix, x - 1, rows, y, cols, visited, str) ||
            hasPathCore(matrix, x, rows, y - 1, cols, visited, str) ||
            hasPathCore(matrix, x + 1, rows, y, cols, visited, str) ||
            hasPathCore(matrix, x, rows, y + 1, cols, visited, str)) {
            return true;
        }
        // 若匹配失败，则标记当前位置为未访问,以便从新开始匹配
        visited[index] = false;
        return false;
    }
};