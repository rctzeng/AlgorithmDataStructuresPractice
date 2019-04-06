class Solution1(object):
    """
    DFS to mark visited points
     - if not visited, connected component count += 1
    """
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        self.grid = grid
        self.V = [[0 for j in range(len(grid[0]))] for i in range(len(grid))]
        ConnectedComponentCount = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if self.V[i][j]==0 and self.grid[i][j]=="1":
                    ConnectedComponentCount += 1
                    self.DFS(i,j)
        return ConnectedComponentCount
    def DFS(self, i, j):
        self.V[i][j]=1
        if self.grid[i][j]=="0": return
        for ai,aj in zip([0,0,1,-1],[1,-1,0,0]):
            ti,tj = i+ai,j+aj
            if ti>=len(self.grid) or ti<0 or tj>=len(self.grid[0]) or tj<0: continue
            if self.grid[ti][tj]=="1":
                if self.V[ti][tj]==0: self.DFS(ti,tj)
        return

class Solution2(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        # BFS
        self.grid = grid
        ConnectedComponentCnt = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if self.grid[i][j]=="1":
                    ConnectedComponentCnt+=1
                    queue = [(i,j)]
                    while queue != []:
                        xi,xj = queue.pop(0)
                        if self.grid[xi][xj]=="0": continue
                        self.grid[xi][xj] = "0" # mark as visited
                        for ai,aj in zip([0,0,1,-1],[1,-1,0,0]):
                            ti,tj = xi+ai, xj+aj
                            if ti>=0 and tj>=0 and ti<len(grid) and tj<len(grid[0]) and self.grid[ti][tj]=="1":
                                queue.append((ti,tj))
        return ConnectedComponentCnt

class Solution3(object):
    """
    Use Union-Find to union connected components
     - find_parent(x):
        while parent[x]!=x: x=parent[x]
        return x
     - union(x,y): parent[find_parent(x)]=find_parent(y)
    """
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        self.parent = {(i,j):(i,j) for i in range(len(grid)) for j in range(len(grid[0])) if grid[i][j]=="1"}
        self.count = len(self.parent)
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]=="0": continue
                p = self.find_parent((i,j))
                for ai,aj in zip([0,0,1,-1],[1,-1,0,0]):
                    xi,xj = i+ai,j+aj
                    if xi>=0 and xj>=0 and xi<len(grid) and xj<len(grid[0]) and grid[xi][xj]=="1":
                        pn = self.find_parent((xi,xj))
                        if pn!=p: self.union(p,pn)
        return self.count
    def find_parent(self, x):
        while self.parent[x]!=x: x=self.parent[x]
        return x
    def union(self, x, y):
        self.parent[self.find_parent(y)] = self.find_parent(x)
        self.count -= 1
