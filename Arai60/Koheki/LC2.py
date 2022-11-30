# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        carry = 0
        res = ListNode(-1)
        pred = res
        while l1 and l2:
            n = l1.val + l2.val + carry
            carry = 0
            if n > 9:
                carry = 1
                n -= 10
            pred.next = ListNode(n)
            pred = pred.next

            l1 = l1.next
            l2 = l2.next
        
        while l1:
            n = l1.val + carry
            carry = 0
            if n > 9:
                carry = 1
                n -= 10
            pred.next = ListNode(n)
            pred = pred.next
            l1 = l1.next

        while l2:
            n = l2.val + carry
            carry = 0
            if n > 9:
                carry = 1
                n -= 10
            pred.next = ListNode(n)
            pred = pred.next
            l2 = l2.next

        if carry:
            pred.next = ListNode(1)

        return res.next

