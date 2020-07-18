//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 示例: 
//
// 输入: [-2,1,-3,4,-1,2,1,-5,4],
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 
//
// 进阶: 
//
// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。 
// Related Topics 数组 分治算法 动态规划 
// 👍 2185 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

// 分治
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int res =INT_MIN;
//        int numSize = int(nums.size());
//        res =maxSubArrayHelper(nums, 0, numSize-1);
//        return res;
//    }
//
//    int maxSubArrayHelper(vector<int> &nums, int left, int right) {
//        if (left == right) {
//            return nums[left];
//        }
//        int mid = (left + right) / 2;
//        int leftSum = maxSubArrayHelper(nums, left ,mid);
//        int rightSum = maxSubArrayHelper(nums, mid+1, right);
//        //必须是mid+1否则当left+1=right时会无限循环
//        int midSum = findMaxCrossingSubArray(nums ,left ,mid ,right);
//        int res = max(leftSum, rightSum);
//        res = max(leftSum, midSum);
//        return res;
//    }
//    int findMaxCrossingSubArray(vector<int> &nums, int left, int mid, int right) {
//        int leftSum = INT_MIN;
//        int sum = 0;
//        for (int i = mid; i >= left; i--) {
//            sum += nums[i];
//            leftSum = max(leftSum, sum);
//        }
//        int rightSum = INT_MIN;
//        sum = 0;
//        for (int i = mid+1; i <= right; i++) {
//            //i=mid+1是为了避免重复用到nums[i]
//            sum += nums[i];
//            rightSum = max(rightSum, sum);
//
//        }
//        return (leftSum + rightSum);
//    }
//};

// 贪心
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for(auto num:nums){
            sum += num;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
