class Solution(object):
    """
    DFS + Sorting
     - Backtrack visiting nodes in the entire DFS tree
     - Remove duplicate by sorting
    """
    def numDistinctIslands(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        self.grid = grid
        ConnectedComponents = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    connected_nodes = self.DFS(i,j)
                    # translate to (0, 0)
                    connected_nodes = [(x[0]-connected_nodes[0][0], x[1]-connected_nodes[0][1]) for x in connected_nodes]
                    connected_nodes.sort(key=lambda x:(x[0],x[1]))
                    ConnectedComponents += [''.join([str(x) for x in connected_nodes])]
        # remove duplicate
        ConnectedComponents = sorted(ConnectedComponents)
        distinct_num = 0
        prev = None
        for c in ConnectedComponents:
            if c!=prev: distinct_num+=1
            prev=c
        return distinct_num

    def DFS(self, x, y):
        if self.grid[x][y]==0: return []
        self.grid[x][y] = 0
        cur_nodes = [(x,y)]
        for ax,ay in zip([1,-1,0,0],[0,0,1,-1]):
            tx, ty = x+ax, y+ay
            if (tx>=0 and tx<len(self.grid)) and (ty>=0 and ty<len(self.grid[0])) and self.grid[tx][ty]==1:
                cur_nodes += self.DFS(tx, ty)
        return cur_nodes
