//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例: 
//
// 给定 1->2->3->4, 你应该返回 2->1->4->3.
// 
// Related Topics 链表 
// 👍 585 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if (!head || !head->next) return head;
//        ListNode *first = head, *second = head->next;
//        first->next = swapPairs(second->next);
//        second->next = first;
//        return second;
//    }
//};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ///终止条件为所有都交换完了的链表
        if(head == NULL || head->next == NULL)
            return head;
        ///递归单元内两个节点做交换
        //定义一个p结点为head->next(该递归单元内第二个节点)
        ListNode *p = head->next;
        //记录第三个节点同时也是下一次递归的head
        ListNode *temp = p->next;
        //使此单元内第二个节点指向第一个节点，即交换位置
        p->next = head;
        //交换完成后的head应指向下一次单元返回的头节点
        head->next = swapPairs(temp);
        //返回该单元的头节点
        return p;

    }
};

//leetcode submit region end(Prohibit modification and deletion)
