class Solution1(object):
    """
    Dynamic Programming + BFS
     - DP[i][j] represent the min sum of all possible paths to (i,j)
     - fill the DP table using BFS orders
    """
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        DP = [[-1 for j in range(len(grid[0]))] for i in range(len(grid))]
        queue = [(0,0)]
        DP[0][0] = grid[0][0]
        done = [[False for j in range(len(grid[0]))] for i in range(len(grid))]
        while queue != []:
            i,j = queue.pop(0)
            if done[i][j]: continue
            for ai,aj in zip([0,0,1,-1],[1,-1,0,0]):
                xi,xj = i+ai,j+aj
                if xi>=0 and xj>=0 and xi<len(grid) and xj<len(grid[0]):
                    if DP[xi][xj]==-1: queue.append((xi,xj))
                    else: DP[i][j] = min(DP[i][j], DP[xi][xj]+grid[i][j]) if DP[i][j]!=-1 else DP[xi][xj]+grid[i][j]
            done[i][j] = True
        return DP[-1][-1]

class Solution2(object):
    """
    As there're only 2 options, we can simplify the DP recurrence
     - DP[i][j] = grid[i][j] + min(DP[i-1][j], DP[i][j-1])
    """
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i-1>=0 and j-1>=0: grid[i][j] += min(grid[i-1][j], grid[i][j-1])
                elif i-1>=0: grid[i][j] += grid[i-1][j]
                elif j-1>=0: grid[i][j] += grid[i][j-1]
        return grid[-1][-1]
