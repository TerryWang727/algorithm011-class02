//假设按照升序排序的数组在预先未知的某个点上进行了旋转。 
//
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。 
//
// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。 
//
// 你可以假设数组中不存在重复的元素。 
//
// 你的算法时间复杂度必须是 O(log n) 级别。 
//
// 示例 1: 
//
// 输入: nums = [4,5,6,7,0,1,2], target = 0
//输出: 4
// 
//
// 示例 2: 
//
// 输入: nums = [4,5,6,7,0,1,2], target = 3
//输出: -1 
// Related Topics 数组 二分查找 
// 👍 857 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 提前判断数组为空直接return -1
// 如果 数组只有一个数 return nums[0] 或 -1
// 二分 比较mid + 1 和 left right
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = int(nums.size()) -1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] >target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid +1;
            else
                hi = mid;
        }
        return  lo == hi && nums[lo] == target ? lo : -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
