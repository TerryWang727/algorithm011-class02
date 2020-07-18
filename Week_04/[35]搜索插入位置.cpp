//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。 
//
// 你可以假设数组中无重复元素。 
//
// 示例 1: 
//
// 输入: [1,3,5,6], 5
//输出: 2
// 
//
// 示例 2: 
//
// 输入: [1,3,5,6], 2
//输出: 1
// 
//
// 示例 3: 
//
// 输入: [1,3,5,6], 7
//输出: 4
// 
//
// 示例 4: 
//
// 输入: [1,3,5,6], 0
//输出: 0
// 
// Related Topics 数组 二分查找 
// 👍 579 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//STL
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
//     }
// };

// 二分查找
//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target) {
//        int n = nums.size();
//        if(n == 0) return 0;
//        int left = 0, right = n - 1;
//        while(left < right) {
//            int mid = left + (right - left) / 2;
//            if(nums[mid] < target) left = mid + 1;
//            else if(nums[mid] == target) return mid;
//            else right = mid;
//        }
//        if(nums[left] < target) return n;
//        return left;
//    }
//};

//内联的lower_bound
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto first = nums.begin(), last = nums.end();
        while (first < last) {
            auto mid = first + ((last - first) >> 1);
            if (*mid < target) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return first - nums.begin();
    }
};


//leetcode submit region end(Prohibit modification and deletion)
