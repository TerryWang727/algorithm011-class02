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

//用swap代替 insert和erase
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        recursion(num, 0, num.size(), res);
        return res;
    }

    void recursion(vector<int> num, int i, int j, vector<vector<int>> &res) {
        if (i == j - 1) {
            res.push_back(num);
            return;
        }

        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j ,res);
        }
    }
};


//leetcode submit region end(Prohibit modification and deletion)
