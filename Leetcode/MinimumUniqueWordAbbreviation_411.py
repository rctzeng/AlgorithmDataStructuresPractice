class Solution(object):
    """
    Backtrack
     - dimension choice: abbreviate or not
     - prune: not expand if duplicate to abbreivations in dictionary words
    """
    def minAbbreviation(self, target, dictionary):
        """
        :type target: str
        :type dictionary: List[str]
        :rtype: str
        """
        # only conflict to words of same length
        dictionary = [w for w in dictionary if len(w)==len(target)]
        all_abbs = set()
        # generate all abbreviations of words in dictionary
        for w in dictionary:
            all_abbs = self.genAllAbbs(w, [], all_abbs, 0)
        shortest_length, shortest_abb = self.findShortestAbbs(all_abbs, target, [], len(target), target, 0)
        return shortest_abb
    def computeLength(self, word):
        digits = [str(i) for i in range(10)]
        # each character and "number" has length 1
        l, c = 0, 0
        for w in word:
            if w in digits: c+=1
            else:
                if c>0: l, c = l+1, 0
                l+=1
        if c>0: l+=1
        return l
    def getAbbStr(self, word):
        # convert k "1"s to "k"
        rw, c = "", 0
        for w in word:
            if w=="1": c+=1
            else:
                if c>0: rw+=str(c)
                rw+=w
                c=0
        if c>0: rw+=str(c)
        return rw
    def genAllAbbs(self, word, cur, all_abbs, level):
        if level==len(word):
            abb = self.getAbbStr(cur)
            if abb not in all_abbs:
                all_abbs.add(abb)
            return all_abbs
        # choices for this dimension
        for choice in [word[level], "1"]:
            all_abbs = self.genAllAbbs(word, cur+[choice], all_abbs, level+1)
        return all_abbs
    def findShortestAbbs(self, dictabbs, word, cur, shortest_length, shortest_abb, level):
        # prune
        if self.computeLength(cur)>shortest_length:
            return shortest_length, shortest_abb
        # check
        if level==len(word):
            cur = self.getAbbStr(cur)
            if cur in dictabbs: return shortest_length, shortest_abb
            l = self.computeLength(cur)
            if l<shortest_length: return l, cur
            return shortest_length, shortest_abb
        # backtrack
        for choice in [word[level], "1"]:
            shortest_length, shortest_abb = self.findShortestAbbs(dictabbs, word, cur+[choice], shortest_length, shortest_abb, level+1)
        return shortest_length, shortest_abb
