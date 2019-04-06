class TLEAttempt(object):
    """
    DFS: O(5^N) => TLE
    """
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.n = n
        self.candidates = ['1','6','9','8','0']
        self.rotate_map = {'1':'1', '6':'9', '9':'6', '8':'8','0':'0'}
        # generate all candidate numbers of length n
        self.solutions = []
        self.DFS([])
        return self.solutions

    def DFS(self, cur):
        if len(cur)==self.n:
            rotated = self.rotate180(cur)
            for i in range(self.n):
                if cur[i]!=rotated[i]: return
            self.solutions += [''.join(cur)]
            return
        for d in self.candidates:
            if d=='0' and cur==[] and self.n>1: continue # prevent leading-zeros
            self.DFS(cur+[d])
        return

    def rotate180(self, digit):
        return [self.rotate_map[d] for d in reversed(digit)]

class Solution(object):
    """
    DFS
     - prevent unnecessary DFS branches
     - Time: O(5^(N/2))
    """
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.n = n
        # generate all candidate numbers of length n
        self.solutions = []
        self.DFS([])
        return self.solutions

    def DFS(self, cur):
        if len(cur)==self.n:
            self.solutions += [''.join(cur)]
            return
        if cur==[] and self.n%2:
            for d in ['0','1','8']: self.DFS(cur+[d])
            return
        if len(cur)+2!=self.n:
            for d,rd in zip(['1','6','8','9','0'],['1','9','8','6','0']): self.DFS([d]+cur+[rd])
        else:
            for d,rd in zip(['1','6','8','9'],['1','9','8','6']): self.DFS([d]+cur+[rd])
        return
