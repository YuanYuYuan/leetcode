from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda intv: intv[0])
        out = [intervals[0]]
        for intv in intervals[1:]:
            if out[-1][1] >= intv[0]:
                out[-1][1] = max(out[-1][1], intv[1])
            else:
                out.append(intv)
        return out

print(Solution().merge([[1, 3], [2, 6], [8, 10], [15, 18]]))
print(Solution().merge([[1, 4], [4, 5]]))


