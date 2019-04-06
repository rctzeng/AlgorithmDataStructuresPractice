class Solution(object):
    """
    DFS+DP
     - DP[i][j] = matched strings; "" if not matched; None if not visited
     - DP[i][j] = DP[i][k] & DP[k][j]
    """
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        self.s = s
        self.wordDict = wordDict
        self.length_lookup = set
        self.matched = [[None for i in range(len(s)+1)] for j in range(len(s)+1)]
        solution = self.DFS(0, len(s))
        return solution if solution!="" else []

    def DFS(self, st, ed):
        # visited
        if self.matched[st][ed]!=None: return self.matched[st][ed]
        # not visited
        for w in self.wordDict:
            if (ed-st)<len(w) or self.s[st:st+len(w)]=="": continue
            if self.s[st:st+len(w)]==w:
                self.matched[st][st+len(w)]=[w]
                right = self.DFS(st+len(w),ed)
                if right!="":
                    for rw in right: self.matched[st][ed] = ['%s %s'%(w, rw)] if self.matched[st][ed]==None else self.matched[st][ed]+['%s %s'%(w, rw)]
        if self.matched[st][ed]==None: self.matched[st][ed]=""
        return self.matched[st][ed]
