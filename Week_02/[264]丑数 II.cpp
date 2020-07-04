//编写一个程序，找出第 n 个丑数。 
//
// 丑数就是质因数只包含 2, 3, 5 的正整数。 
//
// 示例: 
//
// 输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。 
//
// 说明: 
//
// 
// 1 是丑数。 
// n 不超过1690。 
// 
// Related Topics 堆 数学 动态规划 
// 👍 318 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> ugly{0, 1};
        static int m1 = 1, m2 = 1, m3 = 1;//好像是因为static所以秒解
        if (n < ugly.size()) {
            return ugly[n];
        }
        int next = 0;
        while(n >= ugly.size()) {
            next = min(ugly[m1] * 2, min(ugly[m2] * 3, ugly[m3] * 5));
            ugly.push_back(next);
            if (ugly[m1] * 2 == next) {
                ++m1;
            }
            if (ugly[m2] * 3 == next) {
                ++m2;
            }
            if (ugly[m3] * 5 == next) {
                ++m3;
            }
        }
        return ugly[n];
    }
};

//class Solution {
//public:
//    int nthUglyNumber(int n) {
//        if(n <= 0) return false; // get rid of corner cases
//        if(n == 1) return true; // base case
//        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
//        vector<int> k(n);
//        k[0] = 1;
//        for(int i  = 1; i < n ; i ++)
//        {
//            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
//            if(k[i] == k[t2]*2) t2++;
//            if(k[i] == k[t3]*3) t3++;
//            if(k[i] == k[t5]*5) t5++;
//        }
//        return k[n-1];
//    }
//};

//leetcode submit region end(Prohibit modification and deletion)
