from data_strcutres import ListNode


class Solution:

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        #  return self.dummy_head_and_queue(head, n)
        return self.fast_and_slow(head, n)

    def fast_and_slow(self, head: ListNode, n: int) -> ListNode:
        fast = slow = head
        for _ in range(n): fast = fast.next
        # the breaking point is at the start
        if not fast: return head.next
        while fast.next:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return head

    def dummy_head_and_queue(self, head: ListNode, n: int) -> ListNode:
        index = 0
        dummy_head = ListNode(0)
        dummy_head.next = ListNode(0)
        dummy_head.next.next = head
        queue = curr = dummy_head
        while curr:
            if index > n:
                queue = queue.next
            index += 1
            curr = curr.next
        queue.next = queue.next.next
        return dummy_head.next.next

a = ListNode(1)
a.next = ListNode(2)
a.next.next = ListNode(3)
a.next.next.next = ListNode(4)
a.next.next.next.next = ListNode(5)
b = Solution().removeNthFromEnd(a, 5)

while b:
    print(b.val)
    b = b.next
