class Solution(object):
    """
    Smallest just larger number
    ex: 12345 -> 12354 -> 12435 -> 12453 -> 12534 -> 12543 -> 13245
    Step 1. scan from the last digit to find the increasing sequence A
    Step 2. swap x the element just before A with min{y|y in A and y>x}
    Step 3. reverse A

    Time: O(N)
    """
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # Step 1. find A
        inc_idx = len(nums)-1
        for i in range(len(nums)-1,0,-1):
            if nums[i-1]>=nums[i]: inc_idx=i-1
            else: break
        # Step 2. swap the element just before A with min{y|y in A and y>x}
        if inc_idx==0: # no swap available
            pass
        else:
            x = nums[inc_idx-1]
            y_idx = None
            for i in range(len(nums)-1, inc_idx-1, -1):
                if nums[i]>x:
                    y_idx = i
                    break
            # swap
            if y_idx!=None:
                t = nums[y_idx]
                nums[y_idx] = nums[inc_idx-1]
                nums[inc_idx-1] = t
        # Step 3. reverse A
        nums[inc_idx:] = nums[inc_idx:][::-1]
