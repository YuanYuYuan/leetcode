class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        buy_in = None
        sell_out = None
        profit = 0

        for v in prices:
            if buy_in is None or buy_in > v:
                buy_in = v
                sell_out = None
            elif sell_out is None or sell_out < v:
                sell_out = v
                profit = max(profit, sell_out - buy_in)
        return profit


sol = Solution()
assert sol.maxProfit([7,1,5,3,6,4]) == 5
assert sol.maxProfit([7,6,4,3,1]) == 0

