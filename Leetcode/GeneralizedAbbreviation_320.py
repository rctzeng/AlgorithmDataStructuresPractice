class Solution1(object):
    """
    Bit manipulation
     - iterate form 0 ~ 2^n giving all selection combination of n elements
    Complexity
     - Time: O(N 2^N)
    """
    def generateAbbreviations(self, word):
        """
        :type word: str
        :rtype: List[str]
        """
        words = []
        for i in range(2**len(word)):
            w = ""
            bits = self.getBits(i, len(word))
            for j in range(len(bits)):
                if bits[j]==1: w+="1"
                else: w+=word[j]
            words.append(''.join(w))
        # convert k consecutive "1"s to "k"
        abbs = []
        for w in words:
            rw, c = "", 0
            for x in w:
                if x=="1": c+=1
                else:
                    if c>0:
                        rw += str(c)
                        c = 0
                    rw += x
            if c>0: rw += str(c)
            abbs.append(rw)
        return abbs
    def getBits(self, n, l):
        bits = []
        while n>0:
            bits.append(n%2)
            n /= 2
        for i in range(len(bits),l):
            bits.append(0)
        return bits
class Solution2(object):
    """
    Complexity
     - Time: O(N 2^N)
    """
    def generateAbbreviations(self, word):
        """
        :type word: str
        :rtype: List[str]
        """
        return self.Backtrack(word, word, [], 0)
    def Backtrack(self, word, cur_word, words, level):
        if level==len(word):
            # convert k "1"s to "k"
            w, c = "", 0
            for i in range(len(word)):
                if cur_word[i]=="1": c+=1
                else:
                    if c>0:
                        w+=str(c)
                        c=0
                    w+=cur_word[i]
            if c>0: w+=str(c)
            return words+[w]
        # option 1: select not to abbreviate
        words = self.Backtrack(word, cur_word, words, level+1)
        # option 2: select to abbreviate
        words = self.Backtrack(word, cur_word[:level]+"1"+cur_word[level+1:], words, level+1)  # with words returned from option 1
        return words
