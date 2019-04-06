class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num==0: return 'Zero'
        self.num = num
        self.digits = []
        self.special_digits = {1:'One', 2:'Two', 3:'Three', 4:'Four', 5:'Five', 6:'Six', 7:'Seven', 8:'Eight', 9:'Nine', 10:'Ten', 11:'Eleven', 12:'Twelve', 13:'Thirteen', 14:'Fourteen', 15:'Fifteen', 16:'Sixteen', 17:'Seventeen', 18:'Eighteen', 19:'Nineteen', 20:'Twenty', 30:'Thirty', 40:'Forty', 50:'Fifty', 60:'Sixty', 70:'Seventy', 80:'Eighty', 90:'Ninety'}
        self.digit_name = {3:'Thousand', 6:'Million', 9:'Billion'} # 2^31 is at most 2.7 Billion
        # get digits
        self.getDigits()
        # interpret
        rst = ''
        for i in range(0, len(self.digits), 3):
            last2digit_name, last2digit_value = None, self.digits[i+1]*10+self.digits[i] if i+1<len(self.digits) else self.digits[i]
            if last2digit_value in self.special_digits.keys():
                last2digit_name = self.special_digits[last2digit_value]
            elif last2digit_value>0:
                last2digit_name = self.special_digits[10*(last2digit_value//10)] + ' ' + self.special_digits[last2digit_value%10]
            first_digit_name = None
            if i+2<len(self.digits) and self.digits[i+2]>0:
                first_digit_name = self.special_digits[self.digits[i+2]] + ' Hundred'
            if i>0 and (last2digit_name!=None or first_digit_name!=None):
                rst = self.digit_name[i] + ' ' + rst if len(rst)>0 else self.digit_name[i] + rst
            if last2digit_name!=None:
                rst = last2digit_name + ' ' + rst if len(rst)>0 else last2digit_name + rst
            if first_digit_name!=None:
                rst = first_digit_name + ' ' + rst if len(rst)>0 else first_digit_name + rst

        return rst

    def getDigits(self):
        num = self.num
        while num:
            self.digits += [num%10]
            num/=10
        return
