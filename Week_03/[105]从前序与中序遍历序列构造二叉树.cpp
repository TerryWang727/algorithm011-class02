//根据一棵树的前序遍历与中序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
// Related Topics 树 深度优先搜索 数组 
// 👍 557 👎 0


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
//    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
//        return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
//    }
//
//    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
//        if(ps > pe){
//            return nullptr;
//        }
//        TreeNode* node = new TreeNode(preorder[ps]);
//        int pos;
//        for(int i = is; i <= ie; i++){
//            if(inorder[i] == node->val){
//                pos = i;
//                break;
//            }
//        }
//        node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
//        node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
//        return node;
//    }
//};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>m;
        for(int i = 0; i < inorder.size(); i++) m[inorder[i]] = i;
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
    }

    TreeNode* helper(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd, unordered_map<int, int>& m) {
        if(pStart > pEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[pStart]);
        int i = m[preorder[pStart]];
        root->left = helper(preorder, pStart + 1, pStart + i - iStart, inorder, iStart, i - 1, m);
        root->right = helper(preorder, pStart + i - iStart + 1, pEnd, inorder, i + 1, iEnd, m);
        return root;
    }
};



//leetcode submit region end(Prohibit modification and deletion)
