# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    """
    Flip: left child <-> right child
    Q1. Effect on the Pre-Order Traversal?
        cur_node [PreOrder(cur_node.left)] <-> [PreOrder(cur_node.right)]
    Q2. When to flip?
        cur_node.left != voyage[nxt_idx]
    Q3. How to guarantee the # of flips is minimum?
        No idea -> just DFS all possible solution and update the best
    """
    def flipMatchVoyage(self, root, voyage):
        """
        :type root: TreeNode
        :type voyage: List[int]
        :rtype: List[int]
        """
        self.best_flips = None
        self.N = len(voyage)
        self.DFS(root, voyage, [], 0)
        return self.best_flips if self.best_flips!=None else [-1]

    def DFS(self, node, voyage, cur_flips, matched):
        nxt_flips, nxt_matched = None, 0
        if node.val==voyage[0]:
            if node.left==None and node.right==None:
                nxt_flips, nxt_matched = cur_flips, matched+1
            elif node.left==None and node.right!=None:
                nxt_flips, nxt_matched = self.DFS(node.right, voyage[1:], cur_flips, matched+1)
            elif node.right==None and node.left!=None:
                nxt_flips, nxt_matched = self.DFS(node.left, voyage[1:], cur_flips, matched+1)
            else:
                left_st, right_st = -1, -1
                for i in range(1,len(voyage)):
                    if voyage[i]==node.left.val: left_st=i
                    if voyage[i]==node.right.val: right_st=i
                    if left_st!=-1 and right_st!=-1: break
                if left_st==-1 or right_st==-1: return None, 0 # not possible
                if left_st<right_st and left_st==1: # no flip needed
                    nxt_flips, nxt_matched = self.DFS(node.left,
                                                      voyage[left_st:right_st],
                                                      cur_flips,
                                                      matched+1)
                    if nxt_flips!=None:
                        nxt_flips, nxt_matched = self.DFS(node.right,
                                                          voyage[right_st:],
                                                          nxt_flips,
                                                          nxt_matched)
                elif right_st<left_st and right_st==1: # flip
                    nxt_flips, nxt_matched = self.DFS(node.left,
                                                      voyage[left_st:],
                                                      cur_flips+[node.val],
                                                      matched+1)
                    if nxt_flips!=None:
                        nxt_flips, nxt_matched = self.DFS(node.right,
                                                          voyage[right_st:left_st],
                                                          nxt_flips,
                                                          nxt_matched)
        if nxt_matched==self.N: # matched all nodes in voyage
            self.best_flips = self.ChooseShorter(self.best_flips, nxt_flips)
        return nxt_flips, nxt_matched

    def ChooseShorter(self, A, B):
        if A==None: return B
        if B==None: return A
        if len(A)<len(B): return A
        return B
