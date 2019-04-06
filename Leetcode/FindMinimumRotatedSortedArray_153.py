class Solution1(object):
    """
    For-Loop: O(N)
    """
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # minimum is the first if not rotated
        minimum = nums[0]
        # if rotated, find the first decreasing
        for i in range(len(nums)-1):
            if nums[i]>nums[i+1]:
                minimum = nums[i+1]
        return minimum

class Solution2(object):
    """
    Binary Search: O(log N)
    """
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l, r = 0, len(nums)-1
        while l<r:
            m = (l+r)/2
            if nums[l]>nums[m]: r = m
            elif nums[m]>nums[r]: l = m+1
            else: r = l
        return nums[(l+r)/2]
