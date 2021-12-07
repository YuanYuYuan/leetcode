from typing import Optional

class ListNode:
   def __init__(self, val=0, next=None):
       self.val = val
       self.next = next

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        N = 0
        curr = head
        while curr:
            curr = curr.next
            N += 1

        if N == 1:
            return None

        half = N // 2
        count = 0
        curr = head
        prev = curr
        while curr:
            prev = curr
            curr = curr.next
            count += 1
            if count >= half:
                prev.next = curr.next
                break

        return head

a = ListNode(1)
#  a.next = ListNode(2)

b = Solution().deleteMiddle(a)
curr = b
while curr:
    print(curr.val)
    curr = curr.next
