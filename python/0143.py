from data_strcutres import ListNode
from collections import deque


class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        #  self.with_dqueue(head)
        self.reorder_after_middle(head)

    def reorder_after_middle(self, head: ListNode) -> None:
        if not head: return

        # find the middle (the slow cursor)
        fast = slow = head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next

        # reorder the list after middle
        middle = slow
        if not middle.next: return
        cur = middle.next
        while cur.next:
            next = cur.next
            cur.next = next.next
            next.next = middle.next
            middle.next = next

        # merge forward and backward lists
        forward, backward = head, middle.next
        # cut off non-forward part in forward list
        middle.next = None
        # check backward only since it's shorter or equal to forward
        while backward:
            t1, t2 = forward.next, backward.next
            forward.next = backward
            backward.next = t1
            forward, backward = t1, t2


    def with_dqueue(self, head: ListNode) -> None:
        if not head: return

        vec = deque()
        cur = head
        while cur:
            vec.append(cur)
            cur = cur.next

        # link the first i-th element and last i-th element
        # in different direction interleavely.
        prev = vec.popleft()
        left = False
        while vec:
            if left:
                prev.next = vec.popleft()
            else:
                prev.next = vec.pop()
            prev = prev.next
            left = not left

        # trim the end to avoid cycle
        prev.next = None


a = ListNode(1)
#  a.next = ListNode(2)
#  a.next.next = ListNode(3)
#  a.next.next.next = ListNode(4)
#  a.next.next.next.next = ListNode(5)

Solution().reorderList(a)












