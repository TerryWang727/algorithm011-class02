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
// 👍 89 👎 0


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

//class Solution {
//public:
//    vector<int> res;
//    vector<int> preorder(Node* root) {
//        dfs(root);
//        return res;
//    }
//    void dfs(Node* root) {
//        if (!root) return;
//        res.push_back(root->val);
//        for (auto node: root->children) dfs(node);
//    }
//
//};




class Solution {
public:
//method 1 递归
    vector<int> rst;
    // vector<int> preorder(Node* root) {
    //     if(!root) return rst;
    //     rst.push_back(root->val);
    //     if(root->children.empty()) return rst;
    //     for(Node* tmp:root->children)
    //     {
    //         preorder(tmp);
    //     }
    //     return rst;
    // }
//method 2 迭代
    vector<int> preorder(Node* root)
    {
        if(!root) return rst;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            Node* tmp = st.top();
            st.pop();
            if(tmp)
            {
                if(!tmp->children.empty())
                {
                    for(int i=tmp->children.size()-1;i>=0;--i)
                    {
                        st.push(tmp->children[i]);
                    }
                }
                st.push(tmp);
                st.push(nullptr);
            }
            else
            {
                rst.push_back(st.top()->val);
                st.pop();
            }
        }
        return rst;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
