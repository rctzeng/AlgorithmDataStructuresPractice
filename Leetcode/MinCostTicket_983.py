class Solution(object):
    """
    DP[i]: min cost to travel from day i
    DP[i] = min(DP[i], DP[i+1]+cost[0], DP[i+7]+cost[1], DP[i+30]+cost[2])
    """
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        self.days = days
        self.costs = costs
        self.mem = {}
        ans = self.DP(self.days[0])
        return ans

    def DP(self, i):
        if i>self.days[-1]: return 0
        if i in self.mem.keys(): return self.mem[i]
        if i in self.days:
            d1 = self.DP(i+1)+self.costs[0]
            d2 = self.DP(i+7)+self.costs[1]
            d3 = self.DP(i+30)+self.costs[2]
            m = min(d3,min(d1,d2))
        else:
            m = self.DP(i+1)
        self.mem[i] = m
        return m
