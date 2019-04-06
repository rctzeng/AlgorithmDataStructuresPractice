class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        # find first non-whitespace index
        start_idx = 0
        while start_idx<len(str):
            if str[start_idx] != ' ': break
            start_idx += 1
        if start_idx==len(str): return 0 # invalid case
        # get the sign of digit
        sign = 1
        if str[start_idx]=='-': sign, start_idx = -1, start_idx+1
        elif str[start_idx]=='+': start_idx += 1
        MAX, MIN = "2147483647", "2147483648"
        # remove trailing 0
        while start_idx<len(str) and str[start_idx]=='0': start_idx += 1
        if start_idx==len(str): return 0
        # get digit sequence
        end_idx = start_idx
        while end_idx<len(str):
            if str[end_idx] not in ['%s'%i for i in range(10)]: break
            end_idx += 1
        # interpret digit sequence
        if start_idx==end_idx: return 0 # invalid case
        digit_str = str[start_idx:end_idx]
        # check if overflow
        if sign==1:
            if len(MAX)<len(digit_str): return 2147483647
            elif len(MAX)==len(digit_str):
                for i in range(len(MAX)):
                    if MAX[i]<digit_str[i]: return 2147483647
                    elif MAX[i]>digit_str[i]: break
        else:
            if len(MIN)<len(digit_str): return -2147483648
            elif len(MIN)==len(digit_str):
                for i in range(len(MIN)):
                    if MIN[i]<digit_str[i]: return -2147483648
                    elif MIN[i]>digit_str[i]: break
        # convert to digit
        digit = 0
        for c in digit_str:
            digit *= 10
            digit += int(c)
        return digit*sign
