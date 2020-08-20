//实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入: "Hello"
//输出: "hello" 
//
// 示例 2： 
//
// 
//输入: "here"
//输出: "here" 
//
// 示例 3： 
//
// 
//输入: "LOVELY"
//输出: "lovely"
// 
// Related Topics 字符串 
// 👍 129 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    string reverseStr(string s, int k) {
//
//        int n = s.length();
//
//        if (n == 1) return s;
//
//        for (int curInd = 0; curInd < n; curInd += 2 * k) {
//            int endInd = curInd + k < n ? curInd + k : n;
//            reverse(s.begin() + curInd, s.begin() + endInd);
//        }
//        return s;
//    }
//};

// class Solution {
// public:
//     string reverseStr(string s, int k) {
//         for (int i = 0; i < s.size(); i += (2 * k)) {
//             // 1. 每隔 2k 个字符的前 k 个字符进行反转
//             // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
//             if (i + k <= s.size()) {
//                 reverse(s.begin() + i, s.begin() + i + k );
//                 continue;
//             }
//             // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
//             reverse(s.begin() + i, s.begin() + s.size());
//         }
//         return s;
//     }
// };

class Solution {
public:
    string toLowerCase(string str) {
        for(auto& s:str)
            s|=32;
        return str;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
