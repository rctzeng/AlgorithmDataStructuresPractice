class TLEAttempt1(object):
    """
    DFS: O(2^{m+n})
    """
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if matrix==[]: return 0
        self.longest = ""
        self.matrix = matrix
        self.lx, self.ly = len(matrix), len(matrix[0])
        for i in range(self.lx):
            for j in range(self.ly):
                self.DFS(i,j,[self.matrix[i][j]])
        return len(self.longest)
    def DFS(self, i, j, cur):
        if len(cur)>len(self.longest):
            self.longest = cur
        for x,y in zip([0,0,1,-1],[1,-1,0,0]):
            nx, ny = x+i, y+j
            if nx>=0 and nx<self.lx and ny>=0 and ny<self.ly:
                nxt = self.matrix[nx][ny]
                if nxt>cur[-1]:
                    self.DFS(nx,ny,cur+[nxt])

class Solution(object):
    """
    Improve naive DFS by DP table
     - DP[i][j] represent the longest path start from (i,j)
     - Time: O((mn)^2)
    """
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if matrix==[]: return 0
        self.matrix = matrix
        self.lx, self.ly = len(matrix), len(matrix[0])
        self.DP = [[0 for j in range(self.ly)] for i in range(self.lx)]
        ans = 0
        for i in range(self.lx):
            for j in range(self.ly):
                ans = max(ans, self.DFS(i,j))
        return ans

    def DFS(self, i, j):
        if self.DP[i][j]>0: return self.DP[i][j]
        self.DP[i][j] = 1
        for x,y in zip([0,0,1,-1],[1,-1,0,0]):
            nx, ny = x+i, y+j
            if nx>=0 and nx<self.lx and ny>=0 and ny<self.ly and self.matrix[nx][ny]>self.matrix[i][j]:
                self.DP[i][j] = max(self.DP[i][j], 1+self.DFS(nx,ny))
        return self.DP[i][j]

class TLEAttempt2(object):
    """
    Improve naive DFS+DP by better traversal order
     - DP[i][j] represent the longest path start from (i,j)
     - Time: O(mn)
    """
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if matrix==[]: return 0
        m, n = len(matrix), len(matrix[0])
        # generate dependency
        degs, rdep, nodep = {}, {}, []
        for cur in range(m*n):
            i, j = cur//n, cur%n
            fnodep = True
            for x,y in zip([0,0,1,-1],[1,-1,0,0]):
                nx, ny = x+i, y+j
                nxt = nx*n+ny
                if nx>=0 and nx<m and ny>=0 and ny<n and matrix[nx][ny]>matrix[i][j]:
                        degs[cur]=1 if cur not in degs.keys() else degs[cur]+1
                        rdep[nxt]=[cur] if nxt not in rdep.keys() else rdep[nxt]+[cur]
                        fnodep = False
            if fnodep: nodep += [cur]
        # fill the DP table by topological order
        DP, ans = [0 for i in range(m*n)], 0
        while nodep!=[]:
            x = nodep.pop(0)
            DP[x] += 1
            ans = max(ans, DP[x])
            if x in rdep.keys():
                # remove dependency on x and update no dependency nodes
                for v in rdep[x]:
                    DP[v]=max(DP[v],DP[x])
                    degs[v]-=1
                    if degs[v]==0: nodep+=[v]
        return ans
