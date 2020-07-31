//给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。 
//
// 
//
// 示例 1: 
//
// 输入: [2,3,-2,4]
//输出: 6
//解释: 子数组 [2,3] 有最大乘积 6。
// 
//
// 示例 2: 
//
// 输入: [-2,0,-1]
//输出: 0
//解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。 
// Related Topics 数组 动态规划 
// 👍 671 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

//dp
//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        vector <int> maxF(nums), minF(nums);
//        for (int i = 1; i < nums.size(); ++i) {
//            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
//            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
//        }
//        return *max_element(maxF.begin(), maxF.end());
//    }
//};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*vector<int> dpMax(nums);
        vector<int> dpMin(nums);
        int nMax = nums[0];
        for (int i = 1; i < nums.size();i++)
        {
            dpMax[i] = std::max(dpMax[i - 1] * nums[i], std::max(nums[i],dpMin[i - 1] * nums[i]));
            dpMin[i] = std::min(dpMax[i - 1] * nums[i], std::min(nums[i],dpMin[i - 1] * nums[i]));
            nMax = std::max(nMax, dpMax[i]);
        }
        */
        int max = nums[0];
        int min = nums[0];
        int nMax = nums[0];
        for (int i = 1; i < nums.size();i++)
        {
            int tmpMax = std::max(max * nums[i], std::max(nums[i],min * nums[i]));
            int tmpMin = std::min(max * nums[i], std::min(nums[i],min * nums[i]));
            max = tmpMax;
            min = tmpMin;
            nMax = std::max(nMax, max);
        }
        return nMax;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
