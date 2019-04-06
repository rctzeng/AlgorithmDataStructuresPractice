class TLE_Attempt1(object):
    """
    DFS
     - Brute-force to enumerate over all N! permutations
     - Prevent generating duplicate strings by computing occurence of distinct characters
     - Simply check if the given string is a palidrome in O(N)
    Complexity:
     - Time: O(N*N!) -> TLE
    """
    def generatePalindromes(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        char_freq = {}
        for c in s: char_freq[c] = char_freq[c]+1 if c in char_freq.keys() else 1
        self.palidromes = []
        self.DFS([], char_freq)
        return self.palidromes

    def DFS(self, cur, left_char):
        if len(left_char)==0:
            if self.check_palidrome(cur): self.palidromes += [''.join(cur)]
            return
        for k,v in left_char.items():
            tleft = left_char.copy()
            tleft[k] -= 1
            if tleft[k]==0: del tleft[k]
            self.DFS(cur+[k], tleft)
        return

    def check_palidrome(self, x):
        i, j = 0, len(x)-1
        while i<=j:
            if x[i]!=x[j]: return False
            i, j = i+1, j-1
        return True

class Solution(object):
    """
    DFS
     - Create palidrome string by appending same char to begin/end of current string
     - Prevent generating duplicate palidromes by counting occurence of distinct characters
     - Save palidrome O(N) checking and cut some branches
    Complexity:
     - Time: O((N/2)!)
    """
    def generatePalindromes(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        char_freq = {}
        for c in s: char_freq[c] = char_freq[c]+1 if c in char_freq.keys() else 1
        # check if palidrome is possible
        odd_num = 0
        for k,v in char_freq.items():
            if v%2: odd_num += 1
        if not ((odd_num==1 and len(s)%2) or (odd_num==0 and len(s)%2==0)):
            return [] # impossible
        # run DFS to generate all palidrome candidates
        self.palidromes = []
        self.IsOddBegin = False
        if len(s)%2:
            self.IsOddBegin = True
            self.DFS([], char_freq)
        else: self.DFS([], char_freq)
        return self.palidromes

    def DFS(self, cur, left_char):
        if len(left_char)==0:
            self.palidromes += [''.join(cur)]
            return
        if self.IsOddBegin:
            for k,v in left_char.items():
                tleft = left_char.copy()
                tleft[k] -= 1
                if tleft[k]==0: del tleft[k]
                self.IsOddBegin = False
                self.DFS(cur+[k], tleft)
        else:
            for k,v in left_char.items():
                if v>=2:
                    tleft = left_char.copy()
                    tleft[k] -= 2
                    if tleft[k]==0: del tleft[k]
                    self.DFS([k]+cur+[k], tleft)
        return
