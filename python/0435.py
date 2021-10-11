from typing import List


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key=lambda intv: intv[0])
        end = intervals[0][1]
        count = 0
        for [s, e] in intervals[1:]:
            if s < end:
                count += 1
                if e <= end:
                    end = e
            else:
                end = e
        return count
print(Solution().eraseOverlapIntervals([[1, 2], [2, 3], [3, 4], [1, 3]]))
print(Solution().eraseOverlapIntervals([[1, 2], [1, 2], [1, 2]]))

