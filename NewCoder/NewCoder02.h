//
// Created by wenliangsun on 2020/2/5.
//

#ifndef C__ALGORITHM_NEWCODER02_H
#define C__ALGORITHM_NEWCODER02_H

#include <iostream>
#include <string>

#endif //C__ALGORITHM_NEWCODER02_H

using std::string;

/**
 * 题目2：替换空格
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy.
 * 考虑：询问面试官是否在原始字符串上做修改，并且原始字符串上是否有足够多的空余内存。
 * 基于此存在两种不同的方案：
 */
class NewCoder02 {
public:
    /**
     * 思路1：不在原始的字符串上做修改，可以创建新的字符串来进行替换，这样我们可以开辟足够多的内存。
     * 1）首先遍历字符串统计原始字符串中的空格数量；
     * 2）将空格替换为%20，会将原始的字符串长度多增加空格数*2，因为此我们重新创建存放字符串的空间；
     * 3）将字符串依次拷贝到新的字符串中。
     * @param str
     * @param length
     */
    void replaceSpace01(char *str, int length) {
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ')
                count++;
        }
        int new_length = length + count * 2;
        char temp[new_length];
        for (int i = 0, j = 0; i < length; i++) {
            if (str[i] != ' ') {
                temp[j++] = str[i];
            } else {
                temp[j++] = '%';
                temp[j++] = '2';
                temp[j++] = '0';
            }
        }
        std::cout << temp << std::endl;
    }

    /**
     * 思路2：在原来的字符串上进行修改，并且字符串之后有足够的多的空余空间
     * 1）统计原始字符串中空格的数量；
     * 2）考虑如果从前面向后面替换空格，则空格后面的字符会被多次移动，时间复杂度为O(n^2)，我们使用从后向前替换空格；
     * 3）利用两个指针分别指向替换前和替换后字符串的末尾，然后依次向后拷贝字符，当第一个指针遇到空格时，第二个指针向前依次赋值'0','2','%';
     * 4) 当两个指针的指向同一个位置时，替换结束。
     * @param str
     * @param length
     */
    void replaceSpace02(char *str, int length) {
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ')
                count++;
        }
        int p1 = length;
        int p2 = length + count * 2;
        while (p1 != p2) {
            if (str[p1] != ' ') {
                str[p2] = str[p1];
                p1--;
                p2--;
            } else {
                str[p2--] = '0';
                str[p2--] = '2';
                str[p2--] = '%';
                p1--;
            }
        }
    }
};