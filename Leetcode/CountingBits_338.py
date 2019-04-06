class Solution1(object):
    """
    Complexity
     - Time: O(N log N)
    """
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        bits = []
        for i in range(num+1):
            bits.append(sum(self.getBits(i)))
        return bits

    def getBits(self, n):
        bits = []
        while n:
            bits.append(n%2)
            n/=2
        return bits

class Solution2(object):
    """
    Dynamic Programming
     - let DP[i] represent 1s in i's binary representation
     - observe that k = DP[i]+DP[(2**k-1)-i]
     => DP[i] = DP[(2**k-1)-j] - DP[j] // fill the table from 1, ..., ceil(log(num)) works
    """
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        if num==0: return [0]
        dp = [0 for i in range(num*2)]
        cur1s = 1
        while 2**cur1s <= num*2:
            all1s = 2**cur1s-1
            dp[all1s] = cur1s
            for x in range(2**(cur1s-1),2**cur1s-1):
                dp[x] = dp[all1s] - dp[all1s-x]
            cur1s += 1
        return dp[:num+1]
