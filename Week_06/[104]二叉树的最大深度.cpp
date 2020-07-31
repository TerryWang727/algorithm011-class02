//给定一个二叉树，找出其最大深度。 
//
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例： 
//给定二叉树 [3,9,20,null,null,15,7]， 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回它的最大深度 3 。 
// Related Topics 树 深度优先搜索 
// 👍 591 👎 0


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
//    int maxDepth(TreeNode* root) {
//        queue<TreeNode*>q;//队列， q是队列对象
//        if(root!=nullptr){//用nullptr 不用NULL， 这样不会出现构造函数int 空，精确为空指针
//            q.push(root); //此时q队列 size为1，只有根节点
//        }
//        cout << "q.size()="<<q.size()<<endl; //debug专业
//        int depth = 0; //初始depth
//        while(q.size()!=0){ //遍历我们的队列
//            int n = q.size(); // n等于 队列里面元素的个数
//            cout<< "n=q.size()="<< n<<endl;
//            for(int i=0; i<n; i++){ // 把队列里面每个元素都进行处理
//                TreeNode* tr = q.front(); //把队列第一个元素赋值给tr
//                q.pop(); //把队列第一个元素弹出， 先进先出原则
//                if(tr->left!=nullptr){ //如果该元素有左子结点，则把左子结点推入队列q
//                    q.push(tr->left);
//                }
//                if(tr->right!=nullptr){//如果有右子结点，则把右子结点推入队列，
//                    q.push(tr->right);
//                }   //for循环会把本层树的所有结点都作为root遍历他们各自的左右子，然后把该层结点都弹出（在if之前弹出， 弹出前把该元素赋值给tr，每次tr都会更新）
//            }
//            depth++;//一层处理完，depth++， 深度+1 ， 非常好理解
//        }//直到都没有左右子结点， q则没有push元素进来了，则跳出，返回depth
//        return depth;
//    }
//};

//dfs 直接返回 root->left+1||right+1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return max(maxDepth(root->right),maxDepth(root->left))+1;
        //return !root? 0:max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
