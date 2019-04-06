class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if prices==[]: return 0
        m, M, gain = prices[0], prices[0], 0
        for p in prices:
            if p<M: m, M, gain = p, p, gain+M-m
            elif p>M: M = p
        return gain+M-m
