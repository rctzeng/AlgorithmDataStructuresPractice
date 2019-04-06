class Solution(object):
    """
    DP[i][j] = DP[i+1][j-1] & (s[i]==s[j])

    Complexity
     - Time: O(N^2)
     - Space: O(N^2)
    """
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        DP = [0 for i in range(len(s)**2)]
        ans = ""
        for i in reversed(range(len(s))): # len(s)-1, ..., 0
            for j in range(i,len(s)): # i, ..., len(s)
                cur = 1 if s[i]==s[j] else 0
                if i+1>=len(s) or j-1<0 or i==j or i+1==j: last = 1
                else: last = DP[(i+1)*len(s)+j-1]
                DP[i*len(s)+j] = last & cur
                if DP[i*len(s)+j] and j-i+1>len(ans):
                    ans = s[i:j+1]
        return ans
