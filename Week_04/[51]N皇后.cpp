//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 
//
// 上图为 8 皇后问题的一种解法。 
//
// 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。 
//
// 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 示例: 
//
// 输入: 4
//输出: [
// [".Q..",  // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
//解释: 4 皇后问题存在两个不同的解法。
// 
//
// 
//
// 提示： 
//
// 
// 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一到七步
//，可进可退。（引用自 百度百科 - 皇后 ） 
// 
// Related Topics 回溯算法 
// 👍 461 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> res ;

    void dfs(int m , int n , vector<int>& Q) {
        if (m == n) {
            vector<string> temp ;
            string s(n , '.') ;
            for (int i = 0 ; i < n ; ++i) {
                s[Q[i]] = 'Q' ;
                temp.push_back(s) ;
                s[Q[i]] = '.' ;
            }
            res.push_back(temp) ;
            return ;
        }
        for (int i = 0 ; i < n ; ++i) {
            //check
            bool flag = true ;
            for (int j = 0 ; j < m ; ++j) {
                if (Q[j] == i) {
                    flag = false ;
                    break ;
                }
                if (abs(Q[j] - i) == m - j) {
                    flag = false ;
                    break ;
                }
            }
            if (flag) {
                Q.push_back(i) ;
                dfs(m + 1 , n , Q) ;
                Q.pop_back() ;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> Q ;
        dfs(0 , n , Q) ;
        return res ;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
