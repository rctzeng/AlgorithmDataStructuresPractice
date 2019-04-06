class Solution(object):
    """
    Dynamic Programming
     - let DP[i][j] represent unique paths to (i,j)
     - subproblem: DP[i][j] = DP[i-1][j] + DP[i][j-1]
    """
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        DP = [[0 for j in range(len(obstacleGrid[0]))] for i in range(len(obstacleGrid))]
        DP[0][0] = 1 if obstacleGrid[0][0]==0 else 0
        for i in range(len(obstacleGrid)):
            for j in range(len(obstacleGrid[0])):
                if obstacleGrid[i][j]==1: continue
                if i-1>=0 and obstacleGrid[i-1][j]==0:
                    DP[i][j] += DP[i-1][j]
                if j-1>=0 and obstacleGrid[i][j-1]==0:
                    DP[i][j] += DP[i][j-1]
        return DP[-1][-1]
