//给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。 
//
// 示例 1: 
//
// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//输出: false 
// Related Topics 字符串 动态规划 
// 👍 257 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

//动态规划
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length())
            return false;
        bool table[s1.length()+1][s2.length()+1];
        for (int i = 0; i < s1.length()+1; i++) {
            for (int j = 0; j < s2.length()+1; j++) {
                if (i == 0 && j ==0) {
                    table[i][j] = true;
                } else if (i == 0) {
                    table[i][j] = (table[i][j-1] && s2[j-1] == s3[i+j-1]);
                } else if (j == 0) {
                    table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1]);
                } else {
                    table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1]);
                }

            }
        }
        return table[s1.length()][s2.length()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
