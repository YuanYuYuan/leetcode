class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        count = {c: 0 for c in 'balon'}
        for c in text:
            if c in count:
                count[c] += 1

        count['l'] //= 2
        count['o'] //= 2
        return min(count.values())

print(Solution().maxNumberOfBalloons('nlaebolko'))
print(Solution().maxNumberOfBalloons('loonbalxballpoon'))
print(Solution().maxNumberOfBalloons('leetcode'))




