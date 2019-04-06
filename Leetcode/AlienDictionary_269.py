class Solution(object):
    """
    DFS: topological sort
    """
    def alienOrder(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        # get all letters
        chars = []
        for w in words:
            for c in w:
                chars += [c]
        chars = set(chars)
        # let edge(a,b) in graph: represent the priority of a is > b
        graph = {(c1,c2):0 for c1 in chars for c2 in chars}
        for i in range(len(words)):
            for j in range(i+1, len(words)):
                w1, w2 = words[i], words[j]
                l1, l2 = len(w1), len(w2)
                for k in range(min(l1,l2)):
                    if w1[k]!=w2[k]:
                        if graph[(w1[k],w2[k])]==-1: return "" # conflict detected
                        elif graph[(w1[k],w2[k])]==0:
                            graph[(w1[k],w2[k])]=1
                            graph[(w2[k],w1[k])]=-1
                        break
        # print the precendence of letters by topological sort
        self.chars = chars
        self.graph = graph
        self.order = []
        self.visited=set([])
        for c in chars:
            if c not in self.visited:
                self.DFS(c)
        return ''.join(self.order)
    def DFS(self, c1):
        if c1 in self.visited: return
        self.visited.add(c1)
        for c2 in self.chars:
            if self.graph[(c1,c2)]==-1:
                self.DFS(c2)
        self.order += [c1]
