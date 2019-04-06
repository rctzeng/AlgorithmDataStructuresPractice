class Solution(object):
    """
    DFS: O(n!/(k!(n-k!)))
    """
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        self.n = n
        self.k = k
        self.combinations = []
        self.DFS([], 0, 0)
        return self.combinations

    def DFS(self, cur, start_from, taked_num):
        if taked_num==self.k:
            self.combinations += [cur]
            return
        for i in range(start_from, self.n):
            self.DFS(cur+[i+1], i+1, taked_num+1)
        return
