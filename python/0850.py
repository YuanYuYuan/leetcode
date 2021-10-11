from typing import List

M = 10**9 + 7

class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        lst = []
        def cut_or_append(rect, idx):
            if idx >= len(lst):
                lst.append(rect)
            else:
                base = lst[idx]

                # non-overlap
                if rect[0] >= base[2] \
                or rect[1] >= base[3] \
                or rect[2] <= base[0] \
                or rect[3] <= base[1]:
                    cut_or_append(rect, idx+1)

                # overlap
                else:
                    # outside right
                    if rect[2] > base[2]:
                        cut_or_append([base[2], rect[1], rect[2], rect[3]], idx+1)

                    # outside left
                    if rect[0] < base[0]:
                        cut_or_append([rect[0], rect[1], base[0], rect[3]], idx+1)

                    # outside up
                    if rect[3] > base[3]:
                        cut_or_append([max(rect[0], base[0]), base[3], min(rect[2], base[2]), rect[3]], idx+1)

                    # outside down
                    if rect[1] < base[1]:
                        cut_or_append([max(rect[0], base[0]), rect[1], min(rect[2], base[2]), base[1]], idx+1)

        for rect in rectangles:
            cut_or_append(rect, 0)

        sum = 0
        for rect in lst:
            sum += (rect[2]-rect[0]) * (rect[3]-rect[1])

        return sum % M

print(Solution().rectangleArea([[0,0,2,2],[1,0,2,3],[1,0,3,1]]))
print(Solution().rectangleArea([[0,0,1000000000,1000000000]]))

