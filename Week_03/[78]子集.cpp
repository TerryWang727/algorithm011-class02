//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。 
//
// 说明：解集不能包含重复的子集。 
//
// 示例: 
//
// 输入: nums = [1,2,3]
//输出:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//] 
// Related Topics 位运算 数组 回溯算法 
// 👍 641 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
private:
    // 参数1：可选择元素的列表
    // 参数2：现在在选择第几个元素（在选择第一个元素时，depth=0）
    void dfs(vector<int>& nums, int depth) {
        ans.push_back(oneAns);                      // 来者不拒，全部子集都要
        for(int i = depth; i < nums.size(); ++i) {  // 构成子集元素的可选择列表
            oneAns.push_back(nums[i]);              // 把元素添加到一个答案子集中
            dfs(nums, i+1);     // 选择下一个元素
            oneAns.pop_back();  // 回溯操作，和oneAns.push_back(nums[i])对应
        }
    }
    vector<vector<int>> ans;  // 题目答案
    vector<int> oneAns;       // 一个答案子集
};

//leetcode submit region end(Prohibit modification and deletion)
