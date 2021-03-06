//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。 
//
// 示例 1: 
//
// 输入: s = "anagram", t = "nagaram"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s = "rat", t = "car"
//输出: false 
//
// 说明: 
//你可以假设字符串只包含小写字母。 
//
// 进阶: 
//如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
// Related Topics 排序 哈希表


//leetcode submit region begin(Prohibit modification and deletion)

//1.暴力解 统计字母数
//2. sort 然后相等
//3.栈

//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        sort(s.begin(),s.end());
//        sort(t.begin(),t.end());
//        return s==t?true:false;
//    }
//};


 class Solution {
 public:
     bool isAnagram(string s, string t) {
         if (s.size() != t.size()) return false;//若不等直接返回
         int wd[26] = {};
         for (int i = 0; i < s.size(); i++)
             wd[s[i] - 'a']++;
         for (int i = 0; i < t.size(); i++)
             if (--wd[t[i] - 'a'] < 0) return false;//若待判断的值减去t的某个字符后小于0则直接返回，把最好情况的复杂度常数项量级降低
         return true;
     }
 };


//leetcode submit region end(Prohibit modification and deletion)
