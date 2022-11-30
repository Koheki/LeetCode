/* Remove Duplicates from Sorted List II */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *node = dummy;

        while (node->next && node->next->next) {
            if (node->next->val == node->next->next->val) {
                ListNode *tmp = node->next;
                while (tmp->next && tmp->val == tmp->next->val) {
                    tmp = tmp->next;
                }
                node->next = tmp->next;
            } else {
                node = node->next;
            }
        }
        return dummy->next;
    }
};
