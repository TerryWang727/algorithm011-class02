//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
//
// 示例: 
//
// 输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
// Related Topics 回溯算法 
// 👍 307 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//class Solution {
//
//private:
//    vector<vector<int>> res;
//
//    void dfs(int n, int k, int start, vector<int> &path) {
//        if (path.size() == k) {
//            res.push_back(path);
//            return;
//        }
//
//        for (int i = start; i <= n - (k - path.size()) + 1; ++i) {
//            path.push_back(i);
//            dfs(n, k, i+1, path);
//            path.pop_back();
//        }
//    }
//
//public:
//    vector<vector<int>> combine(int n, int k) {
//        if (n <= 0 || k <= 0 || k > n) {
//            return res;
//        }
//        vector<int> path;
//        dfs(n, k, 1, path);
//        return  res;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        vector<vector<int> >results;
//        vector<int> res(k,0);
//        int level = 0;
//        int maxLevel = k-1;
//        int level0_Max = n - k + 1;
//        while(level >= 0){
//            if(++res[level] > level0_Max + level)
//                level--;
//            else if(level == maxLevel)
//                results.push_back(res);
//            else{
//                res[level+1] = res[level];
//                level++;
//            }
//        }
//        return results;
//    }
//};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> ans;
        backtracking(res,ans,n,1,k);
        return res;

    }
    void backtracking(vector<vector<int>> &res,vector<int> &ans,int n,int start,int rest){
        if(rest==0)
        {
            res.push_back(ans);
            return;
        }
        for(int i=start;i<=n-rest+1;i++){
            ans.push_back(i);
            backtracking(res,ans,n,i+1,rest-1);
            ans.pop_back();
        }
    }
};



//leetcode submit region end(Prohibit modification and deletion)
