from typing import List, Optional
from data_strcutres import ListNode

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        curr = head
        n = 0
        while curr:
            curr = curr.next
            n += 1

        num = [n // k] * k
        for i in range(n % k):
            num[i] += 1

        start = head
        out = [None] * k
        for i in range(k):
            if num[i] == 0:
                break
            out[i] = start
            curr = start
            for _ in range(num[i]-1):
                curr = curr.next
            start = curr.next
            curr.next = None

        return out

#  a = None
a = ListNode(1)
curr = a
for v in range(2, 10):
    curr.next = ListNode(v)
    curr = curr.next

b = Solution().splitListToParts(a, 5)
for l in b:
    print('-------------')
    curr = l
    while curr:
        print(curr.val)
        curr = curr.next
