class Solution(object):
    """
    loop through with a: O(N)
     - find solution for b+c=-a by 2Sum in O(N)

    Complexity
     - Time: \sum_{i=1}^N(N-i)=O(N^2)
    """
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums) # O(N log N)
        ans = []
        for i in range(len(nums)):
            # run O(N) 2-sum
            target = -nums[i]
            j, k = i+1, len(nums)-1
            while j<k:
                x = nums[j] + nums[k]
                if x>target: k-=1
                elif x<target: j+=1
                else:
                    ans.append((nums[i],nums[j],nums[k]))
                    k, j = k-1, j+1
        return list(set(ans))
