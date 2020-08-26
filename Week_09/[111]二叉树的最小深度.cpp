//给定一个二叉树，找出其最小深度。 
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//
// 给定二叉树 [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回它的最小深度 2. 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 335 👎 0


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
//class Solution {
//private:
//
//public:
//
////    int minDepth(TreeNode* root) {
////        if (!root) return 0;
////        int L = minDepth(root->left), R = minDepth(root->right);
////        return 1 + (min(L, R) ? min(L, R) : max(L, R));
////    }
////
////    int minDepth(TreeNode* root) {
////        if (!root) return 0;
////        int L = minDepth(root->left), R = minDepth(root->right);
////        return 1 + (L && R ? min(L, R) : max(L, R));
////    }
////
////    int minDepth(TreeNode* root) {
////        if (!root) return 0;
////        int L = minDepth(root->left), R = minDepth(root->right);
////        return 1 + (!L-!R ? max(L, R) : min(L, R));
//    }
//
////    int minDepth(TreeNode* root) {
////        if (!root) return 0;
////        int L = minDepth(root->left), R = minDepth(root->right);
////        return L<R && L || !R ? 1+L : 1+R;
////    }
//
//
//};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr)
        {
            return minDepth(root->right) + 1;
        }
        if (root->right == nullptr)
        {
            return minDepth(root->left) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};


//leetcode submit region end(Prohibit modification and deletion)
