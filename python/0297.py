from data_strcutres import TreeNode


class Codec:

    def serialize(self, root):
        out = []
        def recursive(node):
            if node:
                out.append(str(node.val))
                recursive(node.left)
                recursive(node.right)
            else:
                out.append('N')
        recursive(root)
        return ' '.join(out)

    def deserialize(self, data):
        data_iter = iter(data.split())
        def recursive():
            try:
                val = next(data_iter)
                if val != 'N':
                    node = TreeNode(int(val))
                    node.left = recursive()
                    node.right = recursive()
                    return node
            except:
                return None
        return recursive()



root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.right.left = TreeNode(4)
root.right.right = TreeNode(5)

restore = Codec().deserialize(Codec().serialize(root))

