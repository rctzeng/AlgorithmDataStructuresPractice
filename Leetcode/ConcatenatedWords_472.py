class TLEAttempt(object):
    """
    DFS+DP: O(N^2)
    """
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        self.words = words
        self.DP = {}
        ans = []
        for w in words:
            l = self.DFS(w)
            if l>1: ans.append(w)
        return ans

    def DFS(self, w):
        if len(w)==0: return 0
        if w in self.DP.keys(): return self.DP[w]
        self.DP[w]=-1 # in case of no match
        # match next word
        for nxt_w in self.words:
            if len(nxt_w)>0 and len(nxt_w)<=len(w) and w[:len(nxt_w)]==nxt_w:
                nxt = self.DFS(w[len(nxt_w):])
                if nxt!=-1: self.DP[w]=max(self.DP[w], 1+nxt)
        return self.DP[w]
class Solution1(object):
    """
    DFS: O(NL)
    """
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        self.words = set([w for w in words if len(w)>0])
        ans = []
        for w in words:
            if self.DFS(w, w): ans+=[w]
        return ans

    def DFS(self, w, cur_w):
        if w!=cur_w and w in self.words: return True
        for i in range(len(w)):
            if w[:i] in self.words and self.DFS(w[i:], cur_w): return True
        return False
