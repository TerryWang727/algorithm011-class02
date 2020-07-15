//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 示例 1: 
//
// 输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 说明: 
//
// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。 
// Related Topics 堆 分治算法 
// 👍 607 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

//大顶堆
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        buildMaxHeap(nums);
//        for (int i = 0; i < k - 1; i++) {
//            swap(nums[0], nums[--heapSize]);
//            maxHeapify(nums, 0);
//        }
//        return nums[0];
//    }
//private:
//    int heapSize;
//
//    int left(int i) {
//        return (i << 1) + 1;
//    }
//
//    int right(int i) {
//        return (i << 1) + 2;
//    }
//
//    void maxHeapify(vector<int>& nums, int i) {
//        int largest = i, l = left(i), r = right(i);
//        if (l < heapSize && nums[l] > nums[largest]) {
//            largest = l;
//        }
//        if (r < heapSize && nums[r] > nums[largest]) {
//            largest = r;
//        }
//        if (largest != i) {
//            swap(nums[i], nums[largest]);
//            maxHeapify(nums, largest);
//        }
//    }
//
//    void buildMaxHeap(vector<int>& nums) {
//        heapSize = nums.size();
//        for (int i = (heapSize >> 1) - 1; i >= 0; i--) {
//            maxHeapify(nums, i);
//        }
//    }
//};


//内联函数
class Solution {
public:
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
