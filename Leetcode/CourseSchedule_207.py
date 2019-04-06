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
     Next: Course Schedule III, Graph Valid Tree, Minimum Height Trees
    """
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        indegs = [0 for i in range(numCourses)]
        for a,b in prerequisites: indegs[a]+=1
        nodep = [i for i in range(numCourses) if indegs[i]==0]
        edges = prerequisites[:]
        while len(nodep)>0:
            remove_num = 0
            x = nodep.pop(0)
            redges = edges[:]
            for a,b in edges:
                if b==x:
                    redges.remove([a,b])
                    indegs[a] = indegs[a]-1
                    if indegs[a]==0:
                        nodep.append(a)
                    remove_num += 1
            if len(edges)==0: return True
            edges = redges[:]
        return False

class Solution2(object):
    """
    Depth-First Search
     - DFS on all dependent neighbors
     - return if node has no dependency
    => cannot finish only if cycle presents
    """
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        self.adj = {} # dependency of each node
        for a,b in prerequisites:
            self.adj[a] = self.adj[a]+[b] if a in self.adj.keys() else [b]
        self.stat = [0 for i in range(numCourses)] # 0 for non-visited
        self.cycle = False
        for i in range(numCourses): # in case of isolated paths
            self.DFS(i)
        return not self.cycle

    def DFS(self, cur):
        # prune
        if self.cycle or self.stat[cur]==2: return
        self.stat[cur] = 1 # visiting
        # visite all dependent neighbors
        if cur in self.adj.keys():
            for d in self.adj[cur]:
                if self.stat[d]==0: self.DFS(d)
                if self.stat[d]==1: self.cycle = True
                self.stat[d] = 2 # finish visiting neighbors
        self.stat[cur] = 2 # finish visit this node only if all neighbors are visited
        return

class Solution3(object):
    """
    Depth-First Search
     - DFS on all neighbors depending on this node
     - return if no neighbors depending on this node
    => cannot finish only if cycle presents
    """
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        self.adj = {} # adj[x] contains all courses require x
        for a,b in prerequisites:
            self.adj[b] = self.adj[b]+[a] if b in self.adj.keys() else [a]
        self.stat = [0 for i in range(numCourses)] # 0 for non-visited
        self.cycle = False
        for i in range(numCourses): # in case of isolated paths
            self.DFS(i)
        return not self.cycle

    def DFS(self, cur):
        # prune
        if self.cycle or self.stat[cur]==2: return
        self.stat[cur] = 1 # visiting
        # visite all neighbors dependenting this course
        if cur in self.adj.keys():
            for d in self.adj[cur]:
                if self.stat[d]==0: self.DFS(d)
                if self.stat[d]==1: self.cycle = True
                self.stat[d] = 2 # finish visiting neighbors
        self.stat[cur] = 2 # finish visit this node only if all neighbors are visited
        return
