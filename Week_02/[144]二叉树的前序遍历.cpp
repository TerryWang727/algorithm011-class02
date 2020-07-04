//给定一个二叉树，返回它的 前序 遍历。 
//
// 示例: 
//
// 输入: [1,null,2,3]  
//   1
//    \
//     2
//    /
//   3 
//
//输出: [1,2,3]
// 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 
// 👍 296 👎 0


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
//    vector<int> preorderTraversal(TreeNode* root) {
//        std::stack<TreeNode*> stack;
//        vector<int> vec;
//        TreeNode* cur = root;
//        while (cur != NULL || !stack.empty()) {
//            while (cur!= NULL) { //前序入栈就输出，中序出栈在输出，后续需要访问第二次，出栈在输出
//                stack.push(cur);
//                vec.push_back(cur->val);
//                cur = cur->left;
//            }
//            cur = stack.top();
//            stack.pop();
//            cur = cur->right;//cur = cur->right; 无需判断右子树空与否
//        }
//        return vec;
//    }
//};


class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto p = q.top();
            q.pop();
            if(p == NULL)
            {
                continue;
            }
            result.push_back(p->val);
            q.push(p->right);
            q.push(p->left);
        }

        return result;
    }
};


//leetcode submit region end(Prohibit modification and deletion)
