//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。 
//
// 
//
// 示例： 
//
// s = "leetcode"
//返回 0
//
//s = "loveleetcode"
//返回 2
// 
//
// 
//
// 提示：你可以假定该字符串只包含小写字母。 
// Related Topics 哈希表 字符串 
// 👍 252 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    int firstUniqChar(string s) {
//        vector<int> v(26,0);
//        for (char c:s) v[c - 'a']++;
//        for (int i = 0; i < s.length(); i++) {
//            if (v[s[i] - 'a'] == 1) return i;
//        }
//        return -1;
//    }
//};

 static int n=[](){

     std::ios::sync_with_stdio(false);

     std::cin.tie(nullptr);

     return 0;

 }();
 class Solution {
 public:
     int firstUniqChar(string s) {
         unsigned short table[26];
         memset(table, 0, sizeof table);
         int len = s.length();
         const char *str = s.c_str();
         for(int i = 0; i < s.length(); ++i){
             table[str[i] - 'a']++;
         }
         for (int i = 0; i < s.length(); ++i){
             if (table[str[i] - 'a'] == 1){
                 return i;
             }
         }
         return -1;
     }
 };

//leetcode submit region end(Prohibit modification and deletion)
