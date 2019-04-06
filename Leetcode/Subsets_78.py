class Solution1(object):
    """
    Bit manipulation: O(2^N)
    """
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        subsets = []
        for i in range(2**len(nums)):
            bits = self.getBits(i)
            cur_subset = []
            for j,b in enumerate(bits):
                if b==1: cur_subset.append(nums[j])
            subsets.append(cur_subset)
        return subsets
    def getBits(self, n):
        bits = []
        while n:
            bits.append(n%2)
            n/=2
        return bits
class Solution2(object):
    """
    Backtracking: O(2^N)
    """
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        return self.Backtrack(nums, [], [], 0)
    def Backtrack(self, nums, cur_select, subsets, level):
        if level==len(nums):
            return subsets+[cur_select]
        # not select
        subsets = self.Backtrack(nums, cur_select, subsets, level+1)
        # select
        subsets = self.Backtrack(nums, cur_select+[nums[level]], subsets, level+1)
        return subsets
class Solution3(object):
    """
    DFS: O(2^N)
    """
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.nums = nums
        self.subsets = []
        self.DFS([],0)
        return self.subsets

    def DFS(self, cur_select, i):
        if i==len(self.nums):
            self.subsets.append(cur_select)
            return
        # choice 1: select
        self.DFS(cur_select+[self.nums[i]], i+1)
        # choice 2: not select
        self.DFS(cur_select, i+1)
        return
