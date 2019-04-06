class Solution(object):
    """
    Compute Prefix-Sum
     - find largest difference
    """
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m, M, diff = 0, 0, None
        P = [0]
        for i in range(len(nums)):
            P.append(P[-1]+nums[i])
            if P[i+1]<P[m]:
                if diff != None: diff = max(diff, P[M]-P[m])
                else: diff = P[M]-P[m] if M!=m else diff
                m, M = i+1, i+1
            if P[i+1]>P[M]:
                M = i+1
                diff = max(diff, P[M]-P[m])
        return diff if diff!=None else max(nums)
