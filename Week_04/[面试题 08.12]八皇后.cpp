//设计一种算法，打印 N 皇后在 N × N 棋盘上的各种摆法，其中每个皇后都不同行、不同列，也不在对角线上。这里的“对角线”指的是所有的对角线，不只是平分整
//个棋盘的那两条对角线。 
//
// 注意：本题相对原题做了扩展 
//
// 示例: 
//
//  输入：4
// 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// 解释: 4 皇后问题存在如下两个不同的解法。
//[
// [".Q..",  // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
// 
// Related Topics 回溯算法 
// 👍 26 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

//回溯算法
//class Solution {
//public:
//    vector<vector<string>> ans;
//    void writeRes(vector<pair<int,int>>Queens,int N){ //写入结果
//        string str(N,'.');
//        vector<string> res(N,str);
//        for(auto queen:Queens){
//            res[queen.first][queen.second] = 'Q';
//        }
//        ans.push_back(res);
//    }
//    bool isValid(vector<pair<int,int>>Queens, int x,int y){ // 有效性判断
//        for(auto queen:Queens){
//            if(y == queen.second) return false;  //纵向同线
//            if(abs(x-queen.first)==abs(y-queen.second)) return false; //对角线
//        }
//        return true;
//    }
//    void backtrace(int idx, int N,vector<pair<int,int>>Queens){ //回溯求解
//        if(idx==N){
//            writeRes(Queens,N);
//        }
//        for(int i=0;i<N;++i){
//            if(isValid(Queens,idx,i)){
//                Queens.push_back(make_pair(idx,i));
//                backtrace(idx+1,N,Queens);
//                Queens.pop_back();
//            }
//        }
//    }
//    vector<vector<string>> solveNQueens(int n) {
//
//        backtrace(0,n,vector<pair<int,int>>());
//        return ans;
//    }
//};

//dfs
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
