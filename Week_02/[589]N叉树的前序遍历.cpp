//给定一个 N 叉树，返回其节点值的前序遍历。 
//
// 例如，给定一个 3叉树 : 
//
// 
//
// 
//
// 
//
// 返回其前序遍历: [1,3,5,6,2,4]。 
//
// 
//
// 说明: 递归法很简单，你可以使用迭代法完成此题吗? Related Topics 树 
// 👍 86 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        if (root) st.push(root);
        while (!st.empty()) {
            root = st.top(); st.pop();
            res.push_back(root->val);
            for (auto iter = root->children.rbegin(); iter != root->children.rend(); iter++) {
                if (*iter) st.push(*iter);
            }
        }
        return res;
    }
};


//class Solution {
//private:
//    void travel(Node* root, vector<int>& result) {
//        if (root == nullptr) {
//            return ;
//        }
//
//        result.push_back(root -> val);
//        for (Node* child : root -> children) {
//            travel(child, result);
//        }
//    }
//public:
//    vector<int> preorder(Node* root) {
//        vector<int> result;
//        travel(root, result);
//        return result;
//    }
//};


//leetcode submit region end(Prohibit modification and deletion)
