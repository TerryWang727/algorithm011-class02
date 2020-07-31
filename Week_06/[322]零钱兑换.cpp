//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回
// -1。 
//
// 
//
// 示例 1: 
//
// 输入: coins = [1, 2, 5], amount = 11
//输出: 3 
//解释: 11 = 5 + 5 + 1 
//
// 示例 2: 
//
// 输入: coins = [2], amount = 3
//输出: -1 
//
// 
//
// 说明: 
//你可以认为每种硬币的数量是无限的。 
// Related Topics 动态规划 
// 👍 714 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans)
//    {
//        if (amount == 0)
//        {
//            ans = min(ans, count);
//            return;
//        }
//        if (c_index == coins.size()) return;
//
//        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
//        {
//            coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
//        }
//    }
//
//    int coinChange(vector<int>& coins, int amount)
//    {
//        if (amount == 0) return 0;
//        sort(coins.rbegin(), coins.rend());
//        int ans = INT_MAX;
//        coinChange(coins, amount, 0, 0, ans);
//        return ans == INT_MAX ? -1 : ans;
//    }
//
//};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        coinChange(coins, 0, amount, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }

private:
    void coinChange(const vector<int>& coins, int s, int amount, int count, int& ans) {
        //  recursion terminator
        if (amount == 0) {
            ans = min(ans, count);
            return;
        }
        // process
        // drill down
        // reverse status
        if(s == coins.size()) return;
        const int coin = coins[s];
        for (int k = amount/ coin; k >= 0 && count + k < ans; k--) {
            coinChange(coins, s + 1, amount - k * coin, count + k, ans);
        }

    }
};



// leetcode模板
// 最优题解：
// 思路：
// 时空复杂度：
// O(N*amount)
// 最优解法：

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount + 1, INT_MAX);
//         dp[0] = 0;
//         for (int coin : coins) {
//             for (int i = coin; i <= amount; ++i) {
//                 if (dp[i - coin] != INT_MAX) {
//                     dp[i] = min(dp[i], dp[i - coin] + 1);
//                 }
//             }
//         }
//         return dp[amount] == INT_MAX ? -1 : dp[amount];
//     }
// };
// 变形题：
//leetcode submit region end(Prohibit modification and deletion)
