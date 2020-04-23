#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 堆排序
     * 升序：最大堆 降序：最小堆
     * 将序列构建最大堆，然后将堆顶元素和堆底最后一关元素交换
     * 调整最大堆，再交换，再调整最大堆
     */
    void HeapSort(vector<int>& nums) {
        int length = nums.size();
        // 构建最大堆，从第一个非叶子结点开始，非叶子结点为 length/2-1
        for (int i = length / 2 - 1; i >= 0; i--) {
            heapify(nums, i, length);
        }
        // 依次将最后一个元素和堆顶元素交换，并重新调整最大堆
        for (int i = length - 1; i >= 0; i--) {
            swap(nums, 0, i);
            heapify(nums, 0, i);
        }
    }

   private:
    /**
     * 下沉
     */
    void heapify(vector<int>& nums, int i, int length) {
        int temp = nums[i];
        // 注意这儿循环，如果下沉到最低端，无法下沉
        while (i < length) {
            // 假设最左孩子最大
            int largest = 2 * i + 1;
            // 如果有右孩子，和当前值比较
            if (2 * i + 2 < length && nums[2 * i + 2] > nums[largest]) {
                largest = 2 * i + 2;
            }
            // 如果左孩子不存在或者无法下沉，跳出循环
            if (largest >= length || temp > nums[largest]) {
                break;
            }
            // 和最大的孩子交换
            swap(nums, i, largest);
            // 更新i继续下沉
            i = largest;
        }
    }

    void swap(vector<int>& nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {2, 1, 4, 5, 8, 9, 2, 3};
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    s.HeapSort(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}