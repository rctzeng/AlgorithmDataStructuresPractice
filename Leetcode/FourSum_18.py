class Solution(object):
    """
    Based on 2HeadSearch 2Sum Solution

    Complexity
     - Time: \sum{i=1}^N\sum_{j=i+1}^N (N-i-j)=\sum_{i=1}^N (N-i)^2-(\frac{N(N+1)-i(i+1)}{2})=O(N^3)
    """
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        ans = []
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                k, l = j+1, len(nums)-1
                while k<l: # O(N-i-j)
                    x = nums[i]+nums[j]+nums[k]+nums[l]
                    if x==target:
                        ans.append((nums[i],nums[j],nums[k],nums[l]))
                        k, l = k+1, l-1
                    elif x>target: l-=1
                    elif x<target: k+=1
        return list(set(ans))
