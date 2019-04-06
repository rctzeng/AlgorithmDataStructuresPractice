class Solution1(object):
    """
    Backtrack multiple dimension
     - each dimension represent a distinct number having choices from 0 to its # of occurence
    """
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        num_freq = {}
        for num in nums:
            num_freq[num] = num_freq[num]+1 if num in num_freq.keys() else 1
        num2id = [k for k,v in num_freq.items()] # assign which number corresponding to i-th dimension
        return self.Backtrack(num2id, num_freq, [], [], 0)
    def Backtrack(self, num2id, num_freq, cur, subsets, l):
        if l==len(num2id):
            return subsets+[cur]
        # expand i-th number
        v = []
        for i in range(num_freq[num2id[l]]+1):
            subsets = self.Backtrack(num2id, num_freq, cur+v, subsets, l+1)
            v.append(num2id[l])
        return subsets
class Solution2(object):
    """
    DFS with multiple choices
    """
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # compute occurence of each num
        self.num_freq = {}
        for n in nums: self.num_freq[n] = self.num_freq[n]+1 if n in self.num_freq.keys() else 1
        self.nums = self.num_freq.keys()
        self.subsets = []
        self.DFS([], 0)
        return self.subsets

    def DFS(self, cur_select, num_idx):
        if num_idx == len(self.num_freq.keys()):
            self.subsets += [cur_select]
            return
        cur = self.nums[num_idx]
        for i in range(self.num_freq[cur]+1):
            self.DFS(cur_select+[cur for j in range(i)], num_idx+1)
        return
