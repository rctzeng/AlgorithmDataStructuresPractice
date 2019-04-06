class Solution(object):
    """
    DFS with order: O(N!)
     - it works for single-thread program
    """
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        self.achieved = 0
        self.solution = None
        self.k = k
        self.n = n
        self.DFS([], [i+1 for i in range(n)], 0)
        return self.solution

    def DFS(self, cur, left, level):
        if level==self.n:
            self.achieved += 1
            if self.achieved == self.k:
                self.solution = ''.join(cur)
            return
        if self.solution != None: return
        for i in range(len(left)):
            self.DFS(cur+[str(left[i])], left[:i]+left[i+1:], level+1)
        return
