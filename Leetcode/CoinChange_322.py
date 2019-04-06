class Solution(object):
    """
    Dynamic Programming
    """
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        DP = [-1 for i in range(amount+1)] # DP[x] represents the least coin num required for amount x
        DP[0] = 0
        for coin in coins:
            if coin>amount: continue
            DP[coin]=1
            for i in range(coin,amount+1):
                if DP[i]!=-1 and DP[i-coin]!=-1: DP[i] = min(DP[i],DP[i-coin]+1)
                if DP[i]==-1 and DP[i-coin]!=-1: DP[i] = DP[i-coin]+1
        return DP[amount]
