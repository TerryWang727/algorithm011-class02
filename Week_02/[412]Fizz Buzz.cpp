//写一个程序，输出从 1 到 n 数字的字符串表示。 
//
// 1. 如果 n 是3的倍数，输出“Fizz”； 
//
// 2. 如果 n 是5的倍数，输出“Buzz”； 
//
// 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。 
//
// 示例： 
//
// n = 15,
//
//返回:
//[
//    "1",
//    "2",
//    "Fizz",
//    "4",
//    "Buzz",
//    "Fizz",
//    "7",
//    "8",
//    "Fizz",
//    "Buzz",
//    "11",
//    "Fizz",
//    "13",
//    "14",
//    "FizzBuzz"
//]
// 
//


//leetcode submit region begin(Prohibit modification and deletion)

//暴力解
//class Solution {
//public:
//    vector<string> fizzBuzz(int n) {
//        vector<string> ans;
//        for (int i = 1; i <= n; ++i) {
//            if (i % 15 == 0) ans.emplace_back("FizzBuzz");
//            else if (i % 3 == 0) ans.emplace_back("Fizz");
//            else if (i % 5 == 0) ans.emplace_back("Buzz");
//            else ans.emplace_back(to_string(i));
//        }
//        return ans;
//    }
//};

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        map<int, string> fizzDict;
        fizzDict[3] = "Fizz";
        fizzDict[5] = "Buzz";

        for (int i = 1; i <= n; ++i) {
            string tmp = "";
            for (auto f : fizzDict) if (i % f.first == 0) tmp += f.second;
            if (tmp.empty()) tmp = to_string(i);
            ans.emplace_back(tmp);
        }
        return ans;
    }
};


//leetcode submit region end(Prohibit modification and deletion)
