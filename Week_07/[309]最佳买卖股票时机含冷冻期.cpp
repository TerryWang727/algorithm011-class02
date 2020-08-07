//给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。 
//
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）: 
//
// 
// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。 
// 
//
// 示例: 
//
// 输入: [1,2,3,0,2]
//输出: 3 
//解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出] 
// Related Topics 动态规划 
// 👍 485 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// class Solution {
//     // 0,未持股非冷冻期，1，持股，2，后一天是冷冻期（当天出售过股票）
// public:
//     int maxProfit(vector<int>& prices) {
//         int size = prices.size();
//         vector<vector<int>> dp(size+1,vector<int>(3));
//         dp[0][0] = 0;
//         dp[0][1] = INT_MIN;
//         dp[0][2] = INT_MIN;
//         for(int i=1;i<=size;i++)
//         {
//             dp[i][0] = max(dp[i-1][0],dp[i-1][2]);
//             dp[i][1] = max(dp[i-1][0]-prices[i-1],dp[i-1][1]);
//             dp[i][2] = dp[i-1][1]+prices[i-1];
//         }
//         return max(dp[size][0],dp[size][2]);
//     }
// };
class Solution {
    // 0,未持股非冷冻期，1，持股，2，后一天是冷冻期（当天出售过股票）
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int stat0 = 0;
        int stat1 = INT_MIN;
        int stat2 = INT_MIN;
        int tmpStat0,tmpStat1,tmpStat2;
        for(int i=1;i<=size;i++)
        {
            tmpStat0 = max(stat0,stat2);
            tmpStat1 = max(stat0-prices[i-1],stat1);
            tmpStat2 = stat1+prices[i-1];
            stat0 = tmpStat0;
            stat1 = tmpStat1;
            stat2 = tmpStat2;
        }
        return max(stat0,stat2);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
