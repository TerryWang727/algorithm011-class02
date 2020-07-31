//给定字符串 s 和 t ，判断 s 是否为 t 的子序列。 
//
// 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。 
//
// 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"ae
//c"不是）。 
//
// 示例 1: 
//s = "abc", t = "ahbgdc" 
//
// 返回 true. 
//
// 示例 2: 
//s = "axc", t = "ahbgdc" 
//
// 返回 false. 
//
// 后续挑战 : 
//
// 如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码
//？ 
//
// 致谢: 
//
// 特别感谢 @pbrother 添加此问题并且创建所有测试用例。 
// Related Topics 贪心算法 二分查找 动态规划 
// 👍 247 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    bool isSubsequence(string s, string t) {
//        int n = s.size(), m = t.size();
//        vector<vector<int>> f(m + 1, vector<int>(26, 0));
//        for (int i = 0; i < 26; i++) {
//            f[m][i] = m;
//        }
//        for (int i = m-1; i >= 0; i--) {
//            for (int j = 0; j < 26; j++) {
//                if (t[i] == j + 'a')
//                    f[i][j] = i;
//                else
//                    f[i][j] = f[i+1][j];
//            }
//        }
//        int add = 0;
//        for (int i = 0; i < n; i++) {
//            if (f[add][s[i] - 'a'] == m) {
//                return false;
//            }
//            add = f[add][s[i] - 'a'] + 1;
//        }
//        return true;
//    }
//};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0)
            return true;
        int cmp = 0;
        for(int i = 0; i < t.length(); i++) {
            if(s[cmp] == t[i])
                cmp++;
            else
                continue;
            if(cmp == s.length())
                return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
