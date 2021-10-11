'''
The problem can be optimally solved by min-heap or divide-and-conquer
in time complexity O(n log(k)).

Since min-heap (or priority queue) takes more effort to code,
we use divide-and-conquer here.
'''


from data_strcutres import ListNode
from typing import List

def merge_two_lists(l1: ListNode, l2: ListNode) -> ListNode:
    if l1 and l2:
        if l1.val > l2.val: l1, l2 = l2, l1
        l1.next = merge_two_lists(l1.next, l2)
    return l1 or l2


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        N = len(lists)
        if N == 0: return None
        if N == 1: return lists[0]
        if N == 2: return merge_two_lists(lists[0], lists[1])
        return merge_two_lists(
            self.mergeKLists(lists[:N//2]),
            self.mergeKLists(lists[N//2:])
        )
