from collections import deque
from typing import List


class Node:
    def __init__(self, val: int):
        self.val = val
        self.right = None
        self.left = None


def tree_from_list(lst: List[int]) -> Node:
    itr = iter(lst)
    root = Node(next(itr))
    queue = deque([root])

    while True:
        head = queue.popleft()
        try:
            head.left = Node(next(itr))
            queue.append(head.left)
            head.right = Node(next(itr))
            queue.append(head.right)
        except StopIteration:
            break

    return root


def morris_traversal(root: Node) -> List[int]:
    curr = root
    out = []
    while curr is not None:
        if curr.left is None:
            out.append(curr.val)
            curr = curr.right
        else:
            pred = curr.left
            while pred.right is not None and pred.right is not curr:
                pred = pred.right

            if pred.right is None:
                pred.right = curr
                curr = curr.left
            else:
                pred.right = None
                out.append(curr.val)
                curr = curr.right

    return out


# * Start            * Find pred        * Go left           * Find pred
# out : []           out : []           out : []            out : []
# tree:              tree:              tree:               tree:
#       (1)                (1)                 1                   1
#       / \                / \                / \                 / \
#      2   3             [2]  3             (2)  3              (2)  3
#     / \                / \                / \                 / \
#    4   5              4  [5]             4   5              [4]  5
#                            \                  \               \   \
#                            [1]                 1              [2]  1

#  * Left & return   * Go right          * Clean & return   * Right & return
#  out : [4]         out : []            out : [4,2]        out : [4,2,5]
#  tree:             tree:               tree:              tree:
#         1                 1                   1                  1
#        / \               / \                 / \                / \
#       2   3            (2)  3              (2)  3              2   3
#      / \               / \                 / \                / \
#    (4)  5             4   5               4   5              4  (5)
#      \   \             \   \                   \                  \
#       2   1            (2)  1                   1                  1

#  * Go right         * Clean & return   * Right & return
#  out : [4,2,5]      out : [4,2,5,1]    out : [4,2,5,1,3]
#  tree:              tree:              tree:
#        (1)                (1)                 1
#        / \                / \                / \
#       2   3              2   3              2  (3)
#      / \                / \                / \
#     4   5              4   5              4   5
#          \                                     \
#          (1)                                    1
assert morris_traversal(tree_from_list([1, 2, 3, 4, 5])) == [4, 2, 5, 1, 3]
