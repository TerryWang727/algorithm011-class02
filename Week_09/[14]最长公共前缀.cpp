//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 示例 1: 
//
// 输入: ["flower","flow","flight"]
//输出: "fl"
// 
//
// 示例 2: 
//
// 输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
// 
//
// 说明: 
//
// 所有输入只包含小写字母 a-z 。 
// Related Topics 字符串 
// 👍 1224 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        if (!strs.size()) {
//            return "";
//        }
//        int minLength = min_element(strs.begin(), strs.end(), [](const string& s, const string& t) {return s.size() < t.size();})->size();
//        int low = 0, high = minLength;
//        while (low < high) {
//            int mid = (high - low + 1) / 2 + low;
//            if (isCommonPrefix(strs, mid)) {
//                low = mid;
//            }
//            else {
//                high = mid - 1;
//            }
//        }
//        return strs[0].substr(0, low);
//    }
//
//    bool isCommonPrefix(const vector<string>& strs, int length) {
//        string str0 = strs[0].substr(0, length);
//        int count = strs.size();
//        for (int i = 1; i < count; ++i) {
//            string str = strs[i];
//            for (int j = 0; j < length; ++j) {
//                if (str0[j] != str[j]) {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//};

//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        string res;
//        if(!strs.size())  return res;
//
//        for(int i = 0;;i++){
//            if(strs[0].size()<i) return res;
//            char c = strs[0][i];
//            for(auto& s : strs){
//                if(s.size() < i || s[i] != c) return res;
//            }
//            res += c; //循环外
//        }
//        return res;
//    }
//};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string a = strs[0], b = strs.back();
        int i = 0;
        for(; i < min(a.size(), b.size()); i++) if(a[i] != b[i]) break;
        return a.substr(0, i);
    }
};


//leetcode submit region end(Prohibit modification and deletion)
