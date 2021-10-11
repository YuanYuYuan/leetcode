from typing import List

'''
Method 1:
    Solve it case by case.

        1. ( ) [  ]
        2. [  ] (  )
        3. ( [) ]
        4. [ (] )
        5. ([  ])

        where () denotes the newInterval

Method 2:
    Find the merge part and finally concatenate the left, merge, and right,
    where left and rigt are the unaffected parts.
'''

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        #  return self.case_by_case(intervals, newInterval)
        return self.seperate_and_merge(intervals, newInterval)

    def seperate_and_merge(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        left = []
        right = []
        for intv in intervals:
            if intv[1] < newInterval[0]:
                left.append(intv)
            elif intv[0] > newInterval[1]:
                right.append(intv)
        if len(left) + len(right) != len(intervals):
            merge = [[
                min(intervals[len(left)][0], newInterval[0]),
                max(intervals[~len(right)][1], newInterval[1])
            ]]
        else:
            merge = newInterval
        return left + merge + right



    def case_by_case(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        l, r = newInterval
        out = []
        add = False
        for [x, y] in intervals:
            if l > y:
                out.append([x, y])
            elif x > r:
                if not add:
                    out.append([l, r])
                    add = True
                out.append([x, y])
            else:
                l = min(x, l)
                r = max(y, r)

        if not add:
            out.append([l, r])
        return out


print(Solution().insert([[1,3],[6,9]], [2,5]))


