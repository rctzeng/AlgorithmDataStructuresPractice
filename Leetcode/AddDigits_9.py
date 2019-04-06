class Solution1(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        while num>=10:
            num_next = 0
            while num:
                num_next += num%10
                num /= 10
            num = num_next
        return num

class Solution2(object):
    """
    By math, each 10 creates 1 -> num%9
    """
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num==0: return 0
        return num%9 if num%9 else 9
