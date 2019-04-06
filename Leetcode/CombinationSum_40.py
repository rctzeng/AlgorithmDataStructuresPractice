class Solution(object):
    """
    DFS: O((# of distinct candidates)^(target/min(candidates)))
     - Expand DFS with order
    """
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        num_freq = {}
        for n in candidates: num_freq[n] = num_freq[n]+1 if n in num_freq.keys() else 1
        self.combinations = []
        self.target = target
        self.DFS([], num_freq)
        return self.combinations

    def DFS(self, cur, left):
        cur_sum = sum(cur)
        if cur_sum>self.target: return
        if cur_sum==self.target:
            self.combinations += [cur]
            return
        tleft = left.copy()
        for k,v in left.items():
            del tleft[k] # continuously removing left numbers to prevent duplicate solutions
            select = []
            for i in range(v):
                select += [k]
                self.DFS(cur+select, tleft)
        return
