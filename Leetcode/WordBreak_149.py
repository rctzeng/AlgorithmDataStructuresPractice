class TLEAttempt(object):
    """
    Brute-Force: O((N*max_length)^(len(s)/max_length))
    """
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        self.wordDict = wordDict
        self.found = False
        self.DFS(s)
        return self.found

    def DFS(self, s):
        if len(s)==0:
            self.found = True
            return
        if self.found: return
        for w in self.wordDict:
            if len(s)<len(w): continue
            if s[:len(w)]==w:
                self.DFS(s[len(w):])
        return

class Solution(object):
    """
    Let DP[i][j] = 1 if seperable
     - DP[i][j] = DP[i][k] & DP[k][j]
    Fill the table by DFS order

    Complexity
     - Time: (N^2*max_length)
    """
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        self.wordDict = wordDict
        self.s = s
        self.DP = [[0 for i in range(len(s)+1)] for j in range(len(s)+1)]
        return True if self.DFS(0, len(s))==1 else False

    def DFS(self, st, ed):
        # visited
        if self.DP[st][ed]!=0: return self.DP[st][ed]
        # not split
        for w in self.wordDict:
            if (ed-st+1)<len(w): continue
            if self.s[st:ed]==w:
                self.DP[st][ed]=1
                return 1
        # split
        for k in range(st+1,ed):
            # visited
            if self.DP[st][k]==-1 or self.DP[k][ed]==-1: continue
            # not visited
            if self.DFS(st,k)==1 and self.DFS(k,ed)==1:
                self.DP[st][ed]=1
                break
        if self.DP[st][ed]!=1: self.DP[st][ed]=-1
        return self.DP[st][ed]
