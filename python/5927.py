from typing import Optional, List

class ListNode:
    def __init__(self, val=0, next=None):
       self.val = val
       self.next = next

class Solution:
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        prev = None
        group = 1
        listLen = countList(head)
        while True:
            if listLen >= group:
                isEven = group % 2 == 0
            else:
                isEven = listLen % 2 == 0
            if isEven:
                prev = reverseKNodesAfterCurr(prev, group)
                if not prev: return head
                curr = prev.next
            else:
                for _ in range(group):
                    if not curr: return head
                    prev = curr
                    curr = curr.next
            listLen -= group
            if listLen <= 0: return head
            group += 1

#  W -> A -> B -> C -> D -> Z
#  W ->[A]->(B)-> C -> D -> Z
#  W ->[A]-> B -> C -> D -> Z
#  W -> D -> C -> B -> A -> Z

def countList(head: Optional[ListNode]) -> int:
    count = 0
    while head:
        count += 1
        head = head.next
    return count


def backwardCreate(lst: List[int]) -> Optional[ListNode]:
    head = None
    for v in lst[::-1]:
        node = ListNode(v)
        node.next = head
        head = node
    return head


# (): curr
# 1 ->(2)-> 3 -> 4 -> 5
# 1 -> 3 ->(2)-> 4 -> 5
# 1 -> 4 -> 3 ->(2)-> 5

# 1 -> 3, 3 -> 2, T = 4, 2 -> T
# 1 -> 4, 4 -> 3, T = 5, 2 -> T

# H = 1, C = 2
# T = 4 (= C ->)
# C -> 5 (= C -> ->)
# T -> 3 (= H ->)
# 1 -> T

def reverseKNodesAfterCurr(head: Optional[ListNode], k: int) -> Optional[ListNode]:
    if not head: return None
    curr = head.next
    for _ in range(k-1):
        if not curr or not curr.next: return None
        temp = curr.next
        curr.next = curr.next.next
        temp.next = head.next
        head.next = temp
    return curr


def printList(head: Optional[ListNode]):
    res = []
    while head:
        res.append(str(head.val))
        head = head.next
    print(" -> ".join(res))



#  head = backwardCreate([5, 2, 6, 3, 9, 1, 7, 3, 8, 4])
#  head = backwardCreate([1,1,0,6])
#  head = backwardCreate([2])
head = backwardCreate([0, 4, 2, 1, 3])
#  curr = reverseKNodesAfterCurr(head.next.next, 3)
#  res = []
#  while head:
#      res.append(str(head.val))
#      head = head.next
#  print(" -> ".join(res))
#  print(curr.val)


print("Original list: ")
printList(head)
print()
rev = Solution().reverseEvenLengthGroups(head)
print()
print("After reversion: ")
printList(rev)
