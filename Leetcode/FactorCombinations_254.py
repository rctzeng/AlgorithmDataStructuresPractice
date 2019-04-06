class Solution(object):
    def getFactors(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        self.solutions = []
        if n>1: self.DFS([], n)
        return self.solutions

    def DFS(self, cur, n):
        for i in range(2,int(math.sqrt(n))+1):
            if n%i==0 and (cur==[] or i>=cur[-1]):
                self.DFS(cur+[i],n/i)
        if len(cur)>=1: self.solutions += [cur+[n]]
        return
