"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Codec:

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
            cur += str(node.val)
            for c in node.children:
                cur += self.GenPreOrder(c)
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
                        if len(nodes)>0:
                            nodes = nodes[::-1]
                            stack += [Node(nodes[0], nodes[1:])]
                        elif len(nodes)==0:
                            stack += [None]
                        break
                    else: nodes += [x]
            else: cur_w += d
        return stack[0]


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
