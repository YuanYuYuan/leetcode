from data_strcutres import ListNode

'''
head: 1 -> 2 -> 3 -> N
curr: N

head: 2 -> 3
curr: 1 -> N

head: 3
curr: 2 -> 1 -> N

head: N
curr: 3 -> 2 -> 1 -> N
'''


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        curr = None
        while head:
            next = head.next
            head.next = curr
            curr = head
            head = next
        return curr


