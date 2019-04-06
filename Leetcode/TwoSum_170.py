class TwoSum(object):
    """
    1st attempt with set
     - Add - O(1)
     - Find - worst case O(N)
    => TLE due to large number range
    2nd add simple bound checking to prune too large or small Find()
    => Accept
    """
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.nums = {}
        self.max = None
        self.min = None

    def add(self, number):
        """
        Add the number to an internal data structure..
        :type number: int
        :rtype: void
        """
        if number not in self.nums.keys():
            self.nums[number]=1
            self.max = max(number, self.max) if self.max != None else number
            self.min = min(number, self.min) if self.min != None else number
        elif self.nums[number]==1:
            self.nums[number]=2

    def find(self, value):
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        :type value: int
        :rtype: bool
        """
        if len(self.nums)==0 or (len(self.nums)>0 and value < self.min*2 or value > self.max*2): return False
        for k,v in self.nums.items():
            x = value-k
            if x!=k and x in self.nums.keys(): return True
            if x==k and v>=2: return True
        return False

# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)
