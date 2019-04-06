class TLEAttempt1(object):
    """
    Brute-Force: O(N^3) => TLE
    """
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        solution_cnt = 0
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                if sum(nums[i:j+1])==k: solution_cnt += 1
        return solution_cnt

class TLEAttempt2(object):
    """
    PrefixSum: O(N^2)
    """
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        solution_cnt = 0
        Prefix = [0]
        for i in range(len(nums)):
            Prefix += [Prefix[i]+nums[i]]
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                if Prefix[j+1]-Prefix[i]==k: solution_cnt += 1
        return solution_cnt

class Solution(object):
    """
    HashMap: O(N)
     - similar to 2sum: Prefix_j-Prefix_i==k
     - but requires j>i
    """
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        solution_cnt = 0
        PrefixSum = 0
        PrefixLookup = {0:1}
        for i in range(len(nums)):
            PrefixSum = PrefixSum+nums[i]
            target = (PrefixSum-k)
            if target in PrefixLookup.keys(): solution_cnt += PrefixLookup[target]
            PrefixLookup[PrefixSum] = PrefixLookup[PrefixSum]+1 if PrefixSum in PrefixLookup.keys() else 1
        return solution_cnt
