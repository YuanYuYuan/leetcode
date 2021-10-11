'''
It only needs to update the max_cnt every time we insert in a new element.
When we remove one element, we don't update the max_cnt since the max_len
of optimal substring should be increasing.
'''


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        cnt = {}
        i = 0
        max_len = 0
        max_cnt = 0
        for j, c in enumerate(s):
            if c not in cnt:
                cnt[c] = 1
            else:
                cnt[c] += 1
            max_cnt = max(max_cnt, cnt[c])
            while j - i -  max_cnt >= k:
                cnt[s[i]] -= 1
                i += 1

            max_len = max(max_len, j - i + 1)
        return max_len









