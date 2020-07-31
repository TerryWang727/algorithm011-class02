//给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。 
//
// 示例 1: 
//
// 输入: "(()"
//输出: 2
//解释: 最长有效括号子串为 "()"
// 
//
// 示例 2: 
//
// 输入: ")()())"
//输出: 4
//解释: 最长有效括号子串为 "()()"
// 
// Related Topics 字符串 动态规划 
// 👍 736 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

//栈 O(n) O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxAns = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);

            } else {
                stk.pop();
                if(stk.empty()) {
                    stk.push(i);

                } else {
                    maxAns = max(maxAns, i - stk.top());
                }
            }
        }
        return maxAns;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

