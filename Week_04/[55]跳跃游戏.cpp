//给定一个非负整数数组，你最初位于数组的第一个位置。 
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。 
//
// 判断你是否能够到达最后一个位置。 
//
// 示例 1: 
//
// 输入: [2,3,1,1,4]
//输出: true
//解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
// 
//
// 示例 2: 
//
// 输入: [3,2,1,0,4]
//输出: false
//解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
// 
// Related Topics 贪心算法 数组 
// 👍 738 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int n = nums.size();
//        int rm = 0;
//        for (int i = 0; i < n; ++i) {
//            if (i <= rm) {
//                rm = max(rm, nums[i] + i);
//                if (rm >= n-1)
//                    return true;
//            }
//
//
//        }
//        return false;
//    }
//};

//贪心优化
//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int n = nums.size() - 1, m = nums[0];
//        for (int i = 0; i < m + 1; i++)
//        {
//            m = max(nums[i] + i, m);
//            if (m+1 > n) return true;
//        }
//        return false;
//    }
//};

//检测0是否能跳过去即可

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if(nums.size()==1){
            return true;
        }
        if(nums[0]==0){
            return false;
        }
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i]==0){
                int count = 0;
                for(int j = i-1; j>=0; j--){
                    if(nums[j] > i-j){
                        break;
                    }else{
                        count++;
                    }
                }
                if( count==i){
                    return false;
                }
            }
        }
        return true;
    }

};

//leetcode submit region end(Prohibit modification and deletion)
