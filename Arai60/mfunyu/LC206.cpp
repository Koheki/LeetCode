/* Reverse Linked List */

class Solution {
public:
    ListNode* recursiveList(ListNode* now, ListNode* prev) {
        ListNode* next = now->next;
        now->next = prev;
        if (!next) return now;
        return recursiveList(next, now);
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        return recursiveList(head, NULL);
    }
};
