//翻转一棵二叉树。 
//
// 示例： 
//
// 输入： 
//
//      4
//   /   \
//  2     7
// / \   / \
//1   3 6   9 
//
// 输出： 
//
//      4
//   /   \
//  7     2
// / \   / \
//9   6 3   1 
//
// 备注: 
//这个问题是受到 Max Howell 的 原问题 启发的 ： 
//
// 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。 
// Related Topics 树 
// 👍 483 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//栈迭代

//class Solution {
//public:
//    TreeNode* invertTree(TreeNode* root) {
//        stack<TreeNode*> stk;
//        if(root) stk.push(root);
//        while(stk.size()) {
//            TreeNode* tr = stk.top();
//            stk.pop();
//            swap(tr->left, tr->right);
//            if(tr->left) stk.push(tr->left);
//            if(tr->right) stk.push(tr->right);
//        }
//        return root;
//    }
//};

//递归

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};


//队列迭代
//class Solution {
//public:
//    TreeNode* invertTree(TreeNode* root) {
//        queue<TreeNode*> q;
//        if(root) q.push(root);
//        while(q.size()) {
//            TreeNode* tr = q.front();
//            q.pop();
//            swap(tr->left, tr->right);
//            if(tr->left) q.push(tr->left);
//            if(tr->right) q.push(tr->right);
//        }
//        return root;
//    }
//};

//leetcode submit region end(Prohibit modification and deletion)
