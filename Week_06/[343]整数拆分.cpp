//给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。 
//
// 示例 1: 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。 
//
// 说明: 你可以假设 n 不小于 2 且不大于 58。 
// Related Topics 数学 动态规划 
// 👍 306 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2 || n == 3) return n - 1;
        int three = 0,  two = 0;
        while (n > 0) {
            n -= 3;
            ++three;
            if (n == 2) {
                two = 1;
                break;
            }
            if (n == 1) {
                --three;
                two = 2;
                break;
            }
        }
        return pow(3, three) * pow(2, two);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
