class Solution(object):
    """
    Finding node with start-like subgraph with conditions:
        (1) no out-edge
        (2) N-1 in-edge
    """
    def findJudge(self, N, trust):
        """
        :type N: int
        :type trust: List[List[int]]
        :rtype: int
        """
        indegree = [0 for i in range(N)]
        outdegree = [0 for i in range(N)]
        for a,b in trust:
            indegree[b-1] += 1
            outdegree[a-1] += 1
        for i in range(N):
            if indegree[i]==(N-1) and outdegree[i]==0:
                return i+1
        return -1
