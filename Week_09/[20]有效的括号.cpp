//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 
//
// 注意空字符串可被认为是有效字符串。 
//
// 示例 1: 
//
// 输入: "()"
//输出: true
// 
//
// 示例 2: 
//
// 输入: "()[]{}"
//输出: true
// 
//
// 示例 3: 
//
// 输入: "(]"
//输出: false
// 
//
// 示例 4: 
//
// 输入: "([)]"
//输出: false
// 
//
// 示例 5: 
//
// 输入: "{[]}"
//输出: true 
// Related Topics 栈 字符串 
// 👍 1792 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto x:s) {
            if (x == '(' || x == '{' || x == '[') st.push(x);
            else {
                if (st.empty()) return false;
                if (x == ')' && st.top() == '('
                || x == '}' && st.top() == '{'
                || x == ']' && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        if (st .empty()) return true;
        else return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
