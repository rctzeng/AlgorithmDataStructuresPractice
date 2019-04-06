# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    """
    Traverse BST in-order takes O(N) -> sorted list
    Check 2-sum on sorted list takes O(N)
    """
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        sortedlist = self.Traverse(root)
        l, r = 0, len(sortedlist)-1
        while l<r:
            x = sortedlist[l]+sortedlist[r]
            if x<k: l+=1
            elif x>k: r-=1
            else: return True
        return False
    def Traverse(self, node):
        if node==None: return []
        return self.Traverse(node.left)+[node.val]+self.Traverse(node.right)
