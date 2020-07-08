//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例： 
//
// 输入：n = 3
//输出：[
//       "((()))",
//       "(()())",
//       "(())()",
//       "()(())",
//       "()()()"
//     ]
// 
// Related Topics 字符串 回溯算法 
// 👍 1143 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

//dp[0] = ""
//dp[i]='('+ dp[k]+')'+dp[i-1-k],k=0..i-i
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector< vector<string> > dp(n+1, vector<string>());
        dp[0].push_back("");
        for(int i=1; i<=n; ++i){
            for(int k=0; k<i; ++k){
                for(string s1: dp[k]){
                    for(string s2: dp[i-1-k])
                        dp[i].push_back("("+s1+")"+s2);
                }
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
