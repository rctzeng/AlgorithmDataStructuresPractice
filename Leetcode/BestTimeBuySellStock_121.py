class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if prices==[]: return 0
        m, M, diff = prices[0], prices[0], 0
        for i,p in enumerate(prices):
            if p<m: m, M, diff = p, p, max(diff, M-m)
            elif p>M: M, diff = p, max(diff, p-m)
        return diff
