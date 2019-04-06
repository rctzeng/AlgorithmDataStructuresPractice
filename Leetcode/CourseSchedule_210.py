class Solution1(object):
    """
    Kahn's algorithm
     - maintain a set S = {x | x has no incoming edges}
     - pop node x from S
        * remove all edges (a, x)
        * if deg(a)==0: add a to S
     - finish until run out of S

     Complexity:
      - Time: O(V+E) if represent edge in adjacency lists
    """
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        indegs = [0 for i in range(numCourses)]
        for a,b in prerequisites: indegs[a]+=1
        nodeps = [i for i in range(numCourses) if indegs[i]==0]
        order, edges = [], prerequisites[:]
        while len(nodeps)>0:
            x = nodeps.pop(0)
            redges = edges[:]
            # remove (a,x) in edge sets
            for a,b in edges:
                if b==x:
                    redges.remove([a,b])
                    indegs[a]-=1
                    if indegs[a]==0: nodeps.append(a)
            order.append(x)
            edges = redges[:]
            if len(order)==numCourses: return order
        return []

class Solution2(object):
    """
    Depth-First Search to simulate Kahn's algorithm
     - status: 0 - non-visited, 1 - ongoing (for detecting cycle), 2 - visited
     - return condition: nodes with no dependency
    """
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        self.adj, self.stat, self.order = {}, [0 for i in range(numCourses)], []
        self.cycle = False
        for a,b in prerequisites:
            self.adj[a] = [b] if a not in self.adj.keys() else self.adj[a]+[b]
            self.stat[a] = self.stat[b] = 0
        for i in range(numCourses):
            if self.stat[i]==0: # node non-visited
                self.DFS(i)
        if self.cycle: return []
        return self.order

    def DFS(self, cur):
        if self.cycle: return # no solution due to cycle
        self.stat[cur]=1 # in call
        if cur in self.adj.keys():
            for i in self.adj[cur]: # has dependency
                if self.stat[i]==0:
                    self.DFS(i)
                    self.stat[i]=2 # finish
                if self.stat[i]==1: # detect cycle
                    self.cycle = True
                    return
        self.stat[cur]=2 # finish
        self.order.append(cur)
        return

class Solution3(object):
    """
    Depth-First Search
     - status: 0 - non-visited, 1 - ongoing (for detecting cycle), 2 - visited
     - return condition: nodes with no outgoing edges
        => can have most dependency or isolated points
        => reverse the order
    """
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        self.adj, self.stat, self.order = {}, [0 for i in range(numCourses)], []
        self.cycle = False
        for a,b in prerequisites:
            self.adj[b] = [a] if b not in self.adj.keys() else self.adj[b]+[a]
            self.stat[a] = self.stat[b] = 0
        for i in range(numCourses):
            if self.stat[i]==0: # node non-visited
                self.DFS(i)
        if self.cycle: return []
        return self.order[::-1]

    def DFS(self, cur):
        if self.cycle: return # no solution due to cycle
        self.stat[cur]=1 # in call
        if cur in self.adj.keys():
            for i in self.adj[cur]:
                if self.stat[i]==0:
                    self.DFS(i)
                    self.stat[i]=2 # finish
                if self.stat[i]==1: # detect cycle
                    self.cycle = True
                    return
        self.stat[cur]=2 # finish
        self.order.append(cur)
        return
