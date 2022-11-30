/* Add Two Numbers */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sum = new ListNode();
        ListNode *head = sum;

        while (l1 || l2) {
            if (l1) {
                sum->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum->val += l2->val;
                l2 = l2->next;
            }
            if (l1 || l2 || sum->val > 9) {
                sum->next = new ListNode(sum->val > 9);
            }
            sum->val %= 10;
            sum = sum->next;
        }
        return head;
    }
};
