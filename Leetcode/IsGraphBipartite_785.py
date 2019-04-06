class Solution(object):
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        # convert to adjacency list
        self.G = {}
        for i,g in enumerate(graph):
            for j in g:
                self.G[i]=[j] if i not in self.G.keys() else self.G[i]+[j]
                self.G[j]=[i] if j not in self.G.keys() else self.G[j]+[i]
        if len(self.G)==0: return True
        # color graph by DFS: 1 -> -1 -> 1 -> -1; 0 if unvisited
        self.color = {k:0 for k in self.G.keys()}
        self.IsBipartite = True
        for node in self.G.keys():
            if self.color[node]==0:
                self.color[node] = 1
                self.DFS(node)
        return self.IsBipartite

    def DFS(self, node):
        if not self.IsBipartite: return
        cur_color = self.color[node]
        next_color = -1*cur_color
        for u in self.G[node]:
            if self.color[u]==cur_color:
                self.IsBipartite = False
                return
            elif self.color[u]==next_color: continue
            else:
                self.color[u]=next_color
                self.DFS(u)
        return
