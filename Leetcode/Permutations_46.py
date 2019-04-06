class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.permutations = []
        self.DFS([], nums)
        return self.permutations

    def DFS(self, cur, left):
        if left==[]:
            self.permutations += [cur]
            return
        for i in range(len(left)):
            self.DFS(cur+[left[i]], left[:i]+left[i+1:])
        return
