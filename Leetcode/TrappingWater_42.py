class Solution(object):
    """
    Find first monotically increasing/decreasing sequence

    Complexity:
     - Time: O(N)
     - Space: O(N)
    """
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if len(height)==0: return 0
        trap, rtrap = [], []
        for i,h in enumerate(height):
            if len(trap)==0 or (len(trap)>0 and h>trap[-1][1]): trap.append((i,h))
        for i,h in zip(reversed(range(len(height))), reversed(height)):
            if len(rtrap)==0 or (len(rtrap)>0 and h>rtrap[-1][1]): rtrap.append((i,h))
        total = len(height)*max(height)-sum(height)
        for i,x in enumerate(trap):
            if i>0: total -= (x[0]-trap[0][0])*(x[1]-trap[i-1][1])
        for i,x in enumerate(rtrap):
            if i>0: total -= (rtrap[0][0]-x[0])*(x[1]-rtrap[i-1][1])
        return total
