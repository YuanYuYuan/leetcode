from typing import List

# Andrew's monotone chain convex hull algorithm
# Time complexity; o(log(n))


class Solution:
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        if len(trees) <= 3:
            return trees

        pts = sorted(trees)

        def cross_product(o, p1, p2):
            x1, y1 = p1[0]-o[0], p1[1]-o[1]
            x2, y2 = p2[0]-o[0], p2[1]-o[1]
            return (x1 * y2) - (x2 * y1)

        hull = []
        for pt in pts:
            while len(hull) >= 2 and cross_product(hull[-2], hull[-1], pt) > 0:
                hull.pop()
            hull.append(pt)

        if len(hull) == len(trees):
            return hull

        for pt in pts[-2::-1]:
            while len(hull) >= 2 and cross_product(hull[-2], hull[-1], pt) > 0:
                hull.pop()
            hull.append(pt)

        hull.pop()

        return hull




x = [[1,2],[2,2],[4,2],[5,2],[6,2],[7,2]]
grid = [[0] * 8 for _ in range(8)]
for i, j in x:
    grid[~j][i] = 1
print(x)
for row in grid:
    print(row)
print()


print(Solution().outerTrees([[1,2],[2,2],[4,2],[5,2],[6,2],[7,2]]))
#  print(Solution().outerTrees([[0,0],[0,100],[100,100],[100,0]]))
#  print(Solution().outerTrees([[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]))
#  print(Solution().outerTrees([[1,2],[2,2],[4,2]]))

