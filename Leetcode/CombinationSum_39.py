class Solution(object):
    """
    DFS & Cut
     - To allow duplicate selection, expand DFS on all candidates
     - To remove duplicate solutions, restrict allowed candidates

    Complexity
     - Time: O(len(candidates)^target/min(candidates))
    """
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        self.target = target
        self.solutions = []
        self.DFS([], candidates)
        return self.solutions

    def DFS(self, cur, allowed):
        cur_sum = sum(cur)
        if cur_sum>self.target: return
        if cur_sum==self.target:
            self.solutions += [cur]
            return
        for i in range(len(allowed)): self.DFS(cur+[allowed[i]], allowed[i:])
        return
