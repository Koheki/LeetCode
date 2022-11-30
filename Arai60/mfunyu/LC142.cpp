/* Linked List Cycle II */

class Solution {
public:
    ListNode *hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (slow && fast) {
            slow = slow->next;
            if (!fast->next) return NULL;
            fast = fast->next->next;
            if (slow == fast)
                return fast;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = hasCycle(head);
        while (slow && fast) {
            if (slow == fast)
                return fast;
            slow = slow->next;
            fast = fast->next;
        }
        return NULL;
    }
};
