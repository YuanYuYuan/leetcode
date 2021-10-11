'''
https://leetcode.com/problems/coin-change/


1. Dynamic Programming

Let dp[i] denotes the minimal coins to reach the amount i
then we have a state transition
    dp[i] = min(dp[i-c] if i >= c else MAX for c in coins) + 1

2. BFS

This problem is better addressed by BFS.

Let level represents the reachable amount with a number of coins.
For example, coins = [2, 3], amount = 6

level 0: [0]
level 1: [2, 3]
level 2: [4=2+2, 5=3+2=2+3, 6=3+3]

Then we know that we only need 2 coins to meet the desired 6.

'''


from typing import List


#  class Solution:
#      def coinChange(self, coins: List[int], amount: int) -> int:
#          MAX = amount + 1
#          dp = [0] + [MAX] * amount

#          for i in range(1, amount+1):
#              dp[i] = min(dp[i-c] if i >= c else MAX for c in coins) + 1

#          return -1 if dp[-1] >= MAX else dp[-1]

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        seen = level = {0}
        for step in range(amount+1):
            if amount in level: return step
            level = {l+c for l in level for c in coins if l+c <= amount} - seen
            if not level: return -1
            seen |= level
        return -1

assert Solution().coinChange([1, 2, 5], 11) == 3
