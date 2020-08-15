//给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。 
//
// 重复出现的子串要计算它们出现的次数。 
//
// 示例 1 : 
//
// 
//输入: "00110011"
//输出: 6
//解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。
//
//请注意，一些重复出现的子串要计算它们出现的次数。
//
//另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
// 
//
// 示例 2 : 
//
// 
//输入: "10101"
//输出: 4
//解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
// 
//
// 注意： 
//
// 
// s.length 在1到50,000之间。 
// s 只包含“0”或“1”字符。 
// 
// Related Topics 字符串 
// 👍 182 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    int countBinarySubstrings(string s) {
//        int last, cur, res; last = res = 0; cur = 1;
//        for(int i=1; i<s.size(); i++){
//            if(s[i] == s[i-1]) cur ++;
//            else{last = cur; cur = 1;}
//            if(last >= cur) res++;
//        }
//        return res;
//    }
//};


class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int dp[n];
        dp[0] = 0;
        int zero = 0;
        int one = 0;
        char now = s[0];
        if(now == '0') zero++;
        else one++;
        for(int i = 1; i < n; i++){
            if(s[i] == now){
                if(now == '0'){
                    zero++;
                }
                else one++;
            }
            else{
                if(now =='0'){
                    now  = '1';
                    one = 1;
                }
                else{
                    now ='0';
                    zero = 1;
                }
            }
            if(now == '0' && zero <= one) dp[i] = dp[i-1] + 1;
            else if(now =='1' && one <= zero) dp[i] = dp[i-1] + 1;
            else dp[i] = dp[i-1];
        }
        return dp[n-1];
    }
};



//class Solution {
//public:
//    int countBinarySubstrings(string s) {
//        int ptr = 0, n = s.size(), last = 0, ans = 0;
//        while (ptr < n) {
//            char c = s[ptr];
//            int count = 0;
//            while (ptr < n && s[ptr] == c) {
//                ++ptr;
//                ++count;
//            }
//            ans += min(count, last);
//            last = count;
//        }
//        return ans;
//    }
//};

//leetcode submit region end(Prohibit modification and deletion)
