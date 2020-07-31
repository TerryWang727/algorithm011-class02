//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。 
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 
//
// 
//
// 示例: 
//
// 给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]
// 
// Related Topics 数组 哈希表 
// 👍 8665 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


//分治
//对向量（nums）进行排序，index [k]表示排序后的向量中第k个数字的原始位置。
//使用两个指针（=索引号），一个指针用于较小的数字（开始），另一个指针用于较大的（结束），并将nums [start] + nums [end]与目标进行比较：
//如果nums [start] + nums [end] =目标，则index [start]和index [end]是答案。
//否则，如果nums [start] + nums [end] <目标，将start移至较大的一个（start ++），以使nums [start] + nums [end]变大。
//否则，如果nums [start] + nums [end]>目标，将end移到较小的一个（end--），以使nums [start] + nums [end]变小。
void swap(vector<int>& nums, int i, int j, int* index) {
    // Swap indices at the same time, to keep track of the original indices.
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    temp = index[i];
    index[i] = index[j];
    index[j] = temp;
}
int partition(vector<int>& nums, int start, int end, int* index) {
    // choose a `random' position
    int p = start + rand()%(end-start);
    swap(nums, p, end, index);
    // Now nums[end] is some random value in nums[start, end]
    int r = nums[end];
    int i = start - 1, j = start;
    for(; j < end; j++) {
        if(nums[j]<r) {
            i++;
            swap(nums, i, j, index);
        }
    }
    swap(nums, i+1, end, index);
    return i+1;
}
void quickSort(vector<int>& nums, int start, int end, int* index) {
    if(start<end) {
        int q = partition(nums, start, end, index);
        quickSort(nums, start, q-1, index);
        quickSort(nums, q+1, end, index);
    }
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int* index = new int[size+1];

        // Initialize the origin index to be [0,size)
        for(int i = 0; i < size; i++)
            index[i] = i;
        // Sort the vector: nums, and maintain their original indices.
        quickSort(nums, 0, size-1, index);

        // Two pointers, start and end, look for two numbers add up to the target.
        int start = 0, end = size-1;
        while(start<end) {
            if(nums[start]+nums[end] == target) break;
            else if(nums[start]+nums[end] < target) start++;
            else end--;
        }
        return vector<int> {index[start], index[end]};
    }
};

//leetcode submit region end(Prohibit modification and deletion)
