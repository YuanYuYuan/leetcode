'''
https://leetcode.com/problems/course-schedule/

This is a problem about finding a cycle in a directed graph.
We can use DFS to tackle this.
'''


from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        dep = [[] for _ in range(numCourses)]
        for (a, b) in prerequisites:
            dep[a].append(b)

        checked = set()
        checking = set()
        def hasCycle(i):
            if i in checked: return False
            if i in checking: return True
            checking.add(i)
            if any(hasCycle(j) for j in dep[i]): return True
            checking.remove(i)
            checked.add(i)
            return False

        return not any(hasCycle(c) for c in range(numCourses))


assert Solution().canFinish(2, [[1, 0]]) == True
assert Solution().canFinish(2, [[1, 0], [0, 1]]) == False
assert Solution().canFinish(3, [[1, 0], [0, 2], [2, 1]]) == False
assert Solution().canFinish(3, [[1, 0], [1, 2], [0, 1]]) == False
