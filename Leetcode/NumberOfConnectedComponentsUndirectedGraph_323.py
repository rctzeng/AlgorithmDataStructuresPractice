class Solution(object):
    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        self.G = {}
        for a,b in edges:
            self.G[a]=[b] if a not in self.G.keys() else self.G[a]+[b]
            self.G[b]=[a] if b not in self.G.keys() else self.G[b]+[a]
        self.visited = [0 for i in range(n)]
        connected_component_cnt = 0
        for i in range(n):
            if self.visited[i]==0:
                connected_component_cnt += 1
                self.DFS(i)
        return connected_component_cnt

    def DFS(self, node):
        if self.visited[node]!=0: return
        self.visited[node] = 1 # visiting
        if node not in self.G.keys(): return # no neighbors
        for u in self.G[node]:
            if self.visited[u]==0: self.DFS(u)
        self.visited[node] = 2 # visited
        return
