from data_strcutres import ListNode


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        #  return self.use_set(head)
        return self.tortoise_and_hare(head)

    # O(1) space complexity
    def tortoise_and_hare(self, head: ListNode) -> bool:
        try:
            slow = head.next
            fast = head.next.next
            while slow != fast:
                slow = slow.next
                fast = fast.next.next
            return True
        except:
            return False


    def use_set(self, head: ListNode) -> bool:
        visited = set()
        while head:
            if head in visited:
                return True
            else:
                visited.add(head)
                head = head.next
        return False



