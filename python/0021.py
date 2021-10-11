'''
Note that

The following codes are assginment (create link)

curr.next = l1
curr.next = l2

and the below ones are replacement of pointer (switch link)

l1 = l1.next
l2 = l2.next

so the lower one doesn't affect the upper one.
'''


from data_strcutres import ListNode

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        #  return self.iterative(l1, l2)
        return self.recursive(l1, l2)

    def iterative(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy_root = cur = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next
        cur.next = l1 or l2
        return dummy_root.next

    def recursive(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 and l2:
            if l1.val > l2.val: l1, l2 = l2, l1
            l1.next = self.recursive(l1.next, l2)
        return l1 or l2
