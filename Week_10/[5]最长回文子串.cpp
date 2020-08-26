//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。 
//
// 示例 1： 
//
// 输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
// 
//
// 示例 2： 
//
// 输入: "cbbd"
//输出: "bb"
// 
// Related Topics 字符串 动态规划 
// 👍 2604 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int maxIdx = 0;
        int maxLen = 1;
        int i = 0;

        while (i < s.size()) {
            int start = i;
            int end = i;

            // expand the window from the end if it's an even palindrome
            while (end + 1 < s.size() && s[end] == s[end + 1]) { end++; }
            i = end + 1;

            // expand the window from both sides until it's not longer a palindrome
            while (start - 1 >= 0 && end + 1 < s.size() && s[start - 1] == s[end + 1]) {
                start--, end++;
            }

            int currLen = end - start + 1;
            if (currLen > maxLen) {
                maxIdx = start;
                maxLen = currLen;
            }
        }

        return s.substr(maxIdx, maxLen);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
