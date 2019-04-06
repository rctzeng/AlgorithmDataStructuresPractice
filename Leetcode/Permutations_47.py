class Solution(object):
    """
    DFS+HashMap
     - Use dictionary to count occurence of each distinct integer
     - DFS traverse by visiting distinct integers
    """
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.num_freq = {}
        for n in nums: self.num_freq[n] = self.num_freq[n]+1 if n in self.num_freq.keys() else 1
        self.permutations = []
        self.DFS([], self.num_freq.copy())
        return self.permutations

    def DFS(self, cur, left):
        if len(left)==0:
            self.permutations += [cur]
            return
        # number of choice is the number of distinct integers
        for k in left.keys():
            tleft = left.copy()
            tleft[k] -= 1
            if tleft[k]==0: del tleft[k]
            self.DFS(cur+[k], tleft)
        return
