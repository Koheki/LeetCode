# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:

        def findCycle(head):
            tortoise, hare = head, head
            while hare and hare.next:
                tortoise = tortoise.next
                hare = hare.next.next

                if tortoise == hare:
                    return tortoise
            return None

        def findPoint(head,p):
            p1,p2 = head,p

            while p1 != p2:
                p1 = p1.next
                p2 = p2.next
            
            return p1
        
        p = findCycle(head)

        if p == None:
            return None
        
        return findPoint(head,p)