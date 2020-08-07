//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。 
//
// 示例: 
//
// 输入:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//输出: 1->1->2->3->4->4->5->6 
// Related Topics 堆 链表 分治算法 
// 👍 819 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int start, int end) {
        if (start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode* l1 = merge(lists ,start, mid);
        ListNode* l2 = merge(lists, mid + 1, end);
        return merge(l1, l2);
    }

    ListNode* merge(ListNode* p1, ListNode* p2) {
        if (!p1) return p2;
        if (!p2) return p1;
        if (p1->val <= p2->val) {
            p1->next = merge(p1->next, p2);
            return p1;
        } else {
            p2->next =merge(p1, p2->next);
            return p2;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
