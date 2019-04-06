class TLEAttempt(object):
    """
    Naive: O(N^2)
    """
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        N = len(height)
        ans = 0
        for i in range(N):
            for j in range(i+1, N):
                ans = max(ans, min(height[i], height[j])*(j-i))
        return ans

class Solution(object):
    """
    Consider the two variables: min(height[l], height[r]) and (r-l)
     - if min(height[l], height[r]) is fixed, then (r-l) is the larger the possible
     - if (r-l) is fixed, then move the smaller one of [height[l], height[r]]
    => 2-Pointer Appraoch:
     - Initial: left: goes from 1 -> N, right: goes from N -> 1
     - Always move the smaller one and update answer on the way
    """
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        ans = 0
        l, r = 0, len(height)-1
        while l<r:
            ans = max(ans, min(height[l], height[r])*(r-l))
            if height[l]<height[r]: l+=1
            else: r-=1
        return ans
