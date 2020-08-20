//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 
//
// 说明：每次只能向下或者向右移动一步。 
//
// 示例: 
//
// 输入:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 7
//解释: 因为路径 1→3→1→1→1 的总和最小。
// 
// Related Topics 数组 动态规划 
// 👍 627 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (size_t i = 1; i < n; ++i)
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (size_t i = 1; i < m; ++i)
            for (size_t j = 0; j < n; ++j)
                dp[i][j] = grid[i][j] + (j == 0 ? dp[i - 1][j] : min(dp[i - 1][j], dp[i][j - 1]));
        return dp[m - 1][n - 1];

    }
};
//leetcode submit region end(Prohibit modification and deletion)

