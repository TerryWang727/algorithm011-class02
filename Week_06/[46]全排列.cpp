//给定一个 没有重复 数字的序列，返回其所有可能的全排列。 
//
// 示例: 
//
// 输入: [1,2,3]
//输出:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//] 
// Related Topics 回溯算法 
// 👍 782 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

//class Solution {
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>>res;
//        vector<int>vec;
//        DFS(nums, 0, vec, res);
//        return res;
//    }
//
//    void DFS(vector<int>& nums, int pos, vector<int>& vec, vector<vector<int>>& res) {
//        if(pos == nums.size()){
//            res.push_back(vec);
//            return;
//        }
//        for(int i = 0; i <= vec.size(); i++) {
//            vec.insert(vec.begin() + i, nums[pos]);
//            DFS(nums, pos + 1, vec, res);
//            vec.erase(vec.begin() + i);
//        }
//        return;
//    }
//};

class Solution {
public:

    void dfs(vector<int >& nums, vector<vector<int>>& res, int first, int len) {
        if (first == len) {
            res.push_back(nums);
            return;
        }

        for (int i = first; i < len; ++i) {
            swap(nums[first], nums[i]);
            dfs(nums, res, first + 1, len);
            swap(nums[first], nums[i]);
        }
        return;

    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n == 0) return res;

        dfs(nums, res, 0, n);

        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
