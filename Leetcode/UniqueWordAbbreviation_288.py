class ValidWordAbbr(object):
    """
    word -> abbrevate by (first letter, length-1, last letter)
    Using hashtable with O(N) preprocessing and O(1) lookup
    """
    def __init__(self, dictionary):
        """
        :type dictionary: List[str]
        """
        self.FirstLastPairSet = {}
        for x in dictionary:
            if len(x)>2:
                k=(x[0],x[-1],len(x))
                self.FirstLastPairSet[k] = self.FirstLastPairSet[k]+1 if k in self.FirstLastPairSet.keys() else 1
        self.Words = set(dictionary)

    def isUnique(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if len(word)<=2: return True
        k=(word[0],word[-1],len(word))
        if k not in self.FirstLastPairSet.keys(): return True
        if word in self.Words and self.FirstLastPairSet[k]==1: return True
        return False


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
