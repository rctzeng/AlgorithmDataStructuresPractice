# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    """
    PreOrder with (): (1()())
    """
    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        return self.GenPreOrder(root)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        return self.DecodePreOrder(data)

    def GenPreOrder(self, node):
        cur = '('
        if node!=None:
            cur += str(node.val)+self.GenPreOrder(node.left)+self.GenPreOrder(node.right)
        cur += ')'
        return cur

    def DecodePreOrder(self, data):
        stack = []
        cur_w = ''
        for d in data:
            if d=='(':
                if cur_w!='':
                    stack += [int(cur_w)]
                    cur_w = ''
                stack += [d]
            elif d==')':
                if cur_w!='':
                    stack += [int(cur_w)]
                    cur_w = ''
                nodes = []
                while stack!=[]:
                    x = stack.pop()
                    if x=='(':
                        if len(nodes)==3:
                            t = TreeNode(nodes[2])
                            t.left = nodes[1]
                            t.right = nodes[0]
                            stack += [t]
                        elif len(nodes)==0:
                            stack += [None]
                        break
                    else: nodes += [x]
            else: cur_w += d
        return stack[0]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
