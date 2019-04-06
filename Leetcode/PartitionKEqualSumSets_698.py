class Solution(object):
    """
    DFS: simulate to assign nums into k sets
     - Time: O(k^{N-k}k!)
    """
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        total = sum(nums)
        if total%k!=0: return False
        self.target = total/k
        self.nums = sorted(nums)[::-1]
        if self.nums[-1] > self.target: return False
        self.k = k
        self.sets = [0 for i in range(k)]
        return self.DFS(0)

    def DFS(self, i):
        if i==len(self.nums):
            for s in self.sets:
                if s!=self.target: return False
            return True
        for si in range(self.k):
            self.sets[si] += self.nums[i]
            if self.sets[si]<=self.target and self.DFS(i+1): return True
            self.sets[si] -= self.nums[i]
            if self.sets[si]==0: break
        return False

class TLEAttempt(object):
    """
    DFS: search for valid num sequence
     - Time: O(2^N)
    """
    def canPartitionKSubsets(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        s = sum(nums)
        if s%k!=0: return False
        self.k = k
        self.target = s/k
        nums = sorted(nums)[::-1]
        if nums[-1]>self.target: return False
        return self.DFS(0, nums)

    def DFS(self, cur_k, left):
        s = sum(left)
        if s==0:
            if cur_k!=self.k: return False
            return True
        if cur_k==self.k:
            if s!=0: return False
            return True
        # choose next num so that cur_k*target < sum(left) <= (cur_k+1)*target
        for i in range(len(left)):
            if self.target*(self.k-cur_k-1)<=(s-left[i]) and (s-left[i])<self.target*(self.k-cur_k):
                next_k = cur_k+1 if self.target*(self.k-cur_k-1)==(s-left[i]) else cur_k
                if self.DFS(next_k, left[:i]+left[i+1:]): return True
        return False
