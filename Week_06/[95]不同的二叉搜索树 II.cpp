//给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。 
//
// 
//
// 示例： 
//
// 输入：3
//输出：
//[
//  [1,null,3,2],
//  [3,2,null,1],
//  [3,1,null,null,2],
//  [2,1,3],
//  [1,null,2,null,3]
//]
//解释：
//以上的输出对应以下 5 种不同结构的二叉搜索树：
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 8 
// 
// Related Topics 树 动态规划 
// 👍 519 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    vector<TreeNode*> generateTrees(int n) {
//        if (n == 0) return vector<TreeNode*>(0);
//        return helper(1, n);
//    }
//
//    vector<TreeNode*> helper(int start, int end) {
//        vector<TreeNode*> res;
//        if (start > end) {
//            res.push_back(NULL);
//            return res;
//        }
//        for (int i = start; i < end+1; i++) {
//            vector<TreeNode*> lefts = helper(start, i-1);
//            vector<TreeNode*> rights = helper(i+1, end);
//            for (int j = 0; j < (int)lefts.size(); j++) {
//                for (int k = 0; k < (int)rights.size(); k++) {
//                    TreeNode* root = new TreeNode(i);
//                    root->left = lefts[j];
//                    root->right = rights[k];
//                    res.push_back(root);
//                }
//            }
//        }
//        return res;
//    }
//};


class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
            return vector<TreeNode*>();
        vector<TreeNode*> dp[n][n];
        for(int i=n-1;i>=0;i--)
        {
            dp[i][i].push_back(new TreeNode(i+1,NULL,NULL));
            for(int j=i+1;j<n;j++)
            {
                for(int b=0;b<dp[i+1][j].size();b++)
                    dp[i][j].push_back(new TreeNode(i+1,NULL,dp[i+1][j][b]));
                for(int k=i+1;k<j;k++)
                {
                    for(int a=0;a<dp[i][k-1].size();a++)
                        for(int b=0;b<dp[k+1][j].size();b++)
                            dp[i][j].push_back(new TreeNode(k+1,dp[i][k-1][a],dp[k+1][j][b]));
                }
                for(int a=0;a<dp[i][j-1].size();a++)
                    dp[i][j].push_back(new TreeNode(j+1,dp[i][j-1][a],NULL));
            }
        }
        return dp[0][n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
