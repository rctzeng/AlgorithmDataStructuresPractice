class WordFilter(object):
    """
    Trie: O(NLlogL)
    => Got TLE
    """
    def __init__(self, words):
        """
        :type words: List[str]
        """
        MAX = 11
        self.N = len(words)
        self.PreTrie = [[[] for i in range(26)] for j in range(MAX)]
        self.SufTrie = [[[] for i in range(26)] for j in range(MAX)]
        for i,word in enumerate(words):
            l = len(word)
            for j in range(l):
                self.PreTrie[j][ord(word[j])-ord('a')] += [i]
                self.SufTrie[j][ord(word[l-j-1])-ord('a')] += [i]

    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """
        WordsWithPrefix = None
        for i,c in enumerate(prefix):
            cur = self.PreTrie[i][ord(c)-ord('a')]
            if i==0: WordsWithPrefix=cur
            elif cur==[]:
                WordsWithPrefix=None
                break
            else: # compare WordsWithPrefix and cur
                WordsWithPrefix = self.ExtractCommon(WordsWithPrefix, cur)
                if WordsWithPrefix==None: break

        WordsWithSuffix = None
        for i,c in enumerate(reversed(suffix)):
            cur = self.SufTrie[i][ord(c)-ord('a')]
            if i==0: WordsWithSuffix=cur
            elif cur==[]:
                WordsWithSuffix=None
                break
            else: # compare WordsWithPrefix and cur
                WordsWithSuffix = self.ExtractCommon(WordsWithSuffix, cur)
                if WordsWithSuffix==None: break
        if (WordsWithPrefix==None and prefix!="") or (WordsWithSuffix==None and suffix!=""): return -1
        if prefix=="" and suffix=="": return self.N-1
        if prefix=="": return WordsWithSuffix[-1]
        if suffix=="": return WordsWithPrefix[-1]
        return self.ExtractMax(WordsWithPrefix, WordsWithSuffix)

    def ExtractMax(self, A, B): # O(N)
        iA, iB = len(A)-1, len(B)-1
        while iA>=0 and iB>=0:
            if A[iA]<B[iB]: iB-=1
            elif A[iA]>B[iB]: iA-=1
            else: return A[iA]
        return -1

    def ExtractCommon(self, A, B): # O(N)
        iA, iB = len(A)-1, len(B)-1
        Common = []
        while iA>=0 and iB>=0:
            if A[iA]<B[iB]: iB-=1
            elif A[iA]>B[iB]: iA-=1
            else:
                Common+=[A[iA]]
                iA, iB = iA-1, iB-1
        return Common[::-1] if len(Common)>0 else None

# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
