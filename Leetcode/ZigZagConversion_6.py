class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows==1: return s
        Mod_k = (numRows-1)*2
        Rows = [[] for r in range(numRows)]
        for i,c in enumerate(s):
            for r in range(numRows):
                if i%Mod_k==r or i%Mod_k==(Mod_k-r): Rows[r] += [c]
        return ''.join([''.join(x) for x in Rows])
