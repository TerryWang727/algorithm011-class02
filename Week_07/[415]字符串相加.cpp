//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。 
//
// 
//
// 提示： 
//
// 
// num1 和num2 的长度都小于 5100 
// num1 和num2 都只包含数字 0-9 
// num1 和num2 都不包含任何前导零 
// 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式 
// 
// Related Topics 字符串 
// 👍 244 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
//        string ans = "";
//        while (i >= 0 || j >= 0 || add != 0) {
//            int x = i >= 0 ? num1[i] - '0' : 0;
//            int y = j >= 0 ? num2[j] - '0' : 0;
//            int result = x + y + add;
//            ans.push_back('0' + result % 10);
//            add = result / 10;
//            i --;
//            j --;
//        }
//        reverse(ans.begin(), ans.end());
//        return ans;
//    }
//};


class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        int n = abs(size1-size2);
        int tag = 0;
        string s(n,'0');
        if(size1 >= size2) {
            num2 = s + num2;
        }
        else {
            num1 = s + num1;
        }
        for(int i = max(size1,size2) - 1; i >= 0; i--) {
            int x = (num1[i] - '0') + (num2[i] - '0');
            if(tag == 0) {
                if(x < 10) {
                    num1[i] = x + '0';
                }
                else {
                    num1[i] = x - 10 + '0';
                    tag = 1;
                }
            }
            else {
                if(x<9) {
                    num1[i] = x + 1 + '0';
                    tag = 0;
                }
                else {
                    num1[i] = x - 9 + '0';
                }
            }
        }
        if(tag==0) {
            return num1;
        }
        else{
            return "1" + num1;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
