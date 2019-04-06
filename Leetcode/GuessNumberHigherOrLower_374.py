# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution1(object):
    """
    Binary Search
     - divide region into 2 parts: |left to m-1|m|m+1 to right|
     - worse case T(n)=T(n/2)+2=...=T(1)+2log_2 n
    """
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, r = 1, n
        while l<=r:
            m = (l+r)/2
            g = guess(m)
            if g<0: r = m-1 # guess too high
            elif g>0: l = m+1 # guess too low
            else: return m

class Solution2(object):
    """
    Ternary Search
     - divide region into 3 parts: |left to m1-1|m1|m1+1 to m2-1|m2|m2+1 to right|
     - worst case T(n)=T(n/3)+4=...=T(1)+4log_3 n>T(1)+2log_2 n
    """
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, r = 1, n
        while l<=r:
            m1, m2 = (l+l+r)/3, (l+r+r)/3
            g1, g2 = guess(m1), guess(m2)
            if g1==0: return m1
            if g2==0: return m2
            if g1<0: r = m1-1 # guess too high
            elif g2>0: l = m2+1 # guess too low
            else: l, r = m1+1, m2-1
        return -1
