from typing import List

class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        count = 0
        N = len(tickets)
        while True:
            for i in range(N):
                if tickets[i] == 1 and i == k:
                    return count + 1
                if tickets[i] == 0:
                    continue
                else:
                    tickets[i] -= 1
                    count += 1

#  tickets = [2,3,2]
#  k = 2
tickets = [5,1,1,1]
k = 0
print(Solution().timeRequiredToBuy(tickets, k))
