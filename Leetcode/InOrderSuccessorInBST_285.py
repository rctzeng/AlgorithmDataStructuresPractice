# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderSuccessor(self, root, p):
        """
        :type root: TreeNode
        :type p: TreeNode
        :rtype: TreeNode
        """
        self.ans = None
        self.found = False
        self.InOrderTraversal(root, p)
        return self.ans

    def InOrderTraversal(self, node, p):
        if node.left != None: self.InOrderTraversal(node.left, p)
        if node.val == p.val: self.found = True
        elif self.found:
            if self.ans==None or self.ans.val>node.val: self.ans = node
        if node.right != None: self.InOrderTraversal(node.right, p)
        return
