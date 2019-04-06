class Solution(object):
    """
    Dynamic Programming
     - let DP[i][j] represent unique paths to (i,j)
     - subproblem: DP[i][j] = DP[i-1][j] + DP[i][j-1]
    """
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        DP = [[0 for j in range(n)] for j in range(m)]
        DP[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i-1>=0: DP[i][j] += DP[i-1][j]
                if j-1>=0: DP[i][j] += DP[i][j-1]
        return DP[m-1][n-1]
