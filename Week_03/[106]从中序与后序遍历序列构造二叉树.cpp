//根据一棵树的中序遍历与后序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
// Related Topics 树 深度优先搜索 数组 
// 👍 235 👎 0


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
//public:
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//        int pos = inorder.size()-1;
//        return buildTree(postorder, pos, inorder, 0, inorder.size() - 1);
//    }
//
//    TreeNode* buildTree(vector<int>& postorder, int& pos, vector<int>& inorder, int left, int right) {
//        if (pos < 0 || left > right) return 0;
//        int p = left;
//        while (p <= right && postorder[pos] != inorder[p]) p ++;
//        TreeNode* node = new TreeNode(postorder[pos]);
//        if (p+1 <= right) node->right = buildTree(postorder, --pos, inorder, p+1, right);
//        if (left <= p-1) node->left = buildTree(postorder, --pos, inorder, left, p-1);
//        return node;
//    }
//};

//O(n) re
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> inorder_map;
        // we need a map to look up the position of root in inorder, so
        // that we can divide the tree into separate subtrees,
        // reduces the complexity from n^2 to n assuming good hashing by unodered_map
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        return buildTreeHelper(postorder, 0, inorder.size()-1, 0, postorder.size()-1, inorder_map);
    }

    TreeNode* buildTreeHelper(vector<int>& post, int is, int ie, int ps, int pe, unordered_map<int, int>& inorder_map) {

        if (is > ie || ps > pe) {
            return NULL;
        }
        int root_val = post[pe];
        TreeNode* root = new TreeNode(root_val);
        int i = inorder_map.find(root_val)->second;
        // number of nodes in left subtree
        int l = i-is;
        root->left = buildTreeHelper(post, is, is+l-1, ps, ps+l-1, inorder_map);
        root->right = buildTreeHelper(post, is+l+1, ie, ps+l, pe-1, inorder_map);

        return root;
    }
};


//leetcode submit region end(Prohibit modification and deletion)
