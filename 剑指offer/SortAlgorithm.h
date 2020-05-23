//
// Created by wenliangsun on 2020/2/11.
//

#ifndef C__ALGORITHM_QUICKSORT_H
#define C__ALGORITHM_QUICKSORT_H

#include <vector>

#endif  // C__ALGORITHM_QUICKSORT_H
using namespace std;

class SortAlgorithm {
   public:
    /**
     * 冒泡排序
     * @param array
     * @return
     */
    vector<int> BubbleSort(vector<int> array) {
        for (int i = 0; i < array.size(); ++i) {
            bool flag = true;
            for (int j = 0; j < array.size() - 1 - i; ++j) {  //注意，这儿需要-1
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    flag = false;
                }
            }
            printArray(array);
            if (flag) break;
        }
        return array;
    }

    /**
     * 选择排序
     * @param array
     * @return
     */
    vector<int> SelectSort(vector<int> array) {
        int minIndex;
        for (int i = 0; i < array.size(); ++i) {
            minIndex = i;
            for (int j = i + 1; j < array.size(); ++j) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
            printArray(array);
        }
        return array;
    }

    /**
     * 插入排序
     * 思想:通过构建有序序列，对未排序数据，在已排序序列中从后向前扫描，找到相应的位置插入。
     * 一般来说插入排序都采用in-place在数组上实现：
     * (1) 从第一个元素开始，该元素课认为已经被排序；
     * (2) 取出下一个元素，在已经排序的元素序列中从后向前扫描；
     * (3) 如果该元素(已排序)大于新元素，将该元素右移一个位置；
     * (4) 重复步骤(3)，直到找到已排序的元素小于或等于该元素的位置；
     * (5) 将新元素插入到该位置之后；
     * (6) 重复(2)~(5)
     * @param array
     * @return
     */
    vector<int> InsertionSort(vector<int> array) {
        for (int i = 1; i < array.size(); i++) {  // 遍历数组中的每一个元素
            // 将当前数字插入到之前已经排好序的序列中
            for (int j = i; j > 0; --j) {
                // 从后向前比较，如果前面一个数组比自己大，就和前面一个数字交换。
                if (array[j] < array[j - 1]) {
                    int temp = array[j];
                    array[j] = array[j - 1];
                    array[j - 1] = temp;
                }
            }
            cout << "InsertionSort " << i << ": ";
            printArray(array);
        }
        return array;
    }

    /**
     * 希尔排序
     * 第一个突破O(n^2)的排序算法，是简单插入排序的改进版。它与插入排序算法的不同之处在于，它会优先比较距离较远的元素，希尔排序又叫缩小增量排序
     * 先将整个待排序的记录序列分割成若干个子序列分别进行直接插入排序，具体算法描述：
     * (1) 选择一个增量序列t1,t2,...,tk，其中ti>tj,tk=1;
     * (2) 按增量序列个数k，对序列进行k趟排序；
     * (3)
     * 每趟排序，根据对应的增量ti,将待排序列分割成若干长度为m的子序列，分别对各个子表进行直接插入排序。
     * @param array
     * @return
     */
    vector<int> ShellSort(vector<int> array) {
        for (int gap = array.size() / 2; gap > 0; gap /= 2) {  // 增量
            for (int i = gap; i < array.size(); ++i) {
                for (int j = i - gap; j > 0; j -= gap) {
                    if (array[j] > array[j + gap]) {
                        int temp = array[j];
                        array[j] = array[j + gap];
                        array[j + gap] = temp;
                    }
                }
            }
            cout << "ShellSort " << gap << " : ";
            printArray(array);
        }

        return array;
    }

    /**
     * 归并排序
     * 归并排序是建立在归并操作上的一种有效的排序算法，该算法是分治法的一个典型应用。
     * 将已有序的子序列合并，得到完全有序的序列。
     * (1) 把长度为n的输入序列分为两个长度为n/2的子序列；
     * (2) 对这两个子序列分别进行归并排序；
     * (3) 将两个排序好的子序列合并成一个最终的排序序列。
     */
    vector<int> MergeSort(vector<int> array) {
        int left = 0;
        int right = array.size() - 1;
        return MergeSort(array, left, right);
    }

    vector<int> MergeSort(vector<int> array, int left, int right) {
        int mid = (left + right) / 2;

        if (left < right) {
            array = MergeSort(array, left, mid);
            cout << "左侧：";
            printArray(array);
            array = MergeSort(array, mid + 1, right);
            cout << "右侧：";
            printArray(array);
            array = merge(array, left, mid, right);
            cout << "合并：";
            printArray(array);
        }
        return array;
    }

    /**
     * 快速排序
     * 基本思想：通过一趟排序将待排序的数据分割成独立的两部分，其中一部分的所有数据比另一部分的所有数据要小，
     * 在按照这个方法对这两部分数据进行快速排序，整个排序过程可以递归进行，使得整个数据变得有序。
     * 快速排序使用分治法的思想：
     * (1) 从数列中挑选出一个元素，称为基准；
     * (2)
     * 重新排列数列，使得该基准左侧的元素都小于或等于它，右侧的元素都大于它；
     * (3) 递归重排左子序列和右子序列。
     *
     */
    vector<int> QuickSort(vector<int> array) {
        return QuickSort(array, 0, array.size() - 1);
    }

    vector<int> QuickSort(vector<int> array, int left, int right) {
        if (left < right) {
            int index = partition(array, left, right);
            cout << index << endl;
            if (index > left) {
                array = QuickSort(array, left, index - 1);
            }
            cout << "左侧：";
            printArray(array);
            if (index < right) {
                array = QuickSort(array, index + 1, right);
            }
            cout << "右侧：";
            printArray(array);
        }
        return array;
    }

   private:
    /**
     * 合并操作
     * @param array
     * @param left
     * @param mid
     * @param right
     * @return
     */
    vector<int> merge(vector<int> array, int left, int mid, int right) {
        int len = right - left + 1;  // 计算临时数组长度
        int temp[array.size()];      // 临时数组
        int leftIndex = left;        // 左侧指针
        int rightIndex = mid + 1;    // 右侧指针
        int index = left;            // 临时数组指针
        while (leftIndex <= mid && rightIndex <= right) {  //合并
            if (array[leftIndex] < array[rightIndex]) {
                temp[index++] = array[leftIndex++];
            } else {
                temp[index++] = array[rightIndex++];
            }
        }
        while (leftIndex <= mid) {
            temp[index++] = array[leftIndex++];
        }
        while (rightIndex <= right) {
            temp[index++] = array[rightIndex++];
        }
        printArray(array);
        while (left <= right) {  // 将临时数组中的数字拷贝到原来的数组中
            array[left] = temp[left];
            left++;
        }
        return array;
    }

    int partition(vector<int> array, int left, int right) {
        int small = left;
        int index = left;
        for (int i = index + 1; i <= right; ++i) {
            if (array[i] < array[small]) {
                index++;
                int temp = array[i];
                array[i] = array[index];
                array[index] = temp;  
            }
        }
        int temp = array[small];
        array[small] = array[index];
        array[index] = temp;
        return index;
    }

    void printArray(vector<int> array) {
        for (int i = 0; i < array.size(); ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};
