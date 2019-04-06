# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    """
    Sort + Stack
     - Sort all boundary values in ascending order
     - Push/pop values to stack if meeting start/end boundary points
     - Merged boundary points are those points at stack depth = 0
    """
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        # start boundary point goes before end boundary points
        nums = [(x.start, 0) for i,x in enumerate(intervals)] + [(x.end, 1) for i,x in enumerate(intervals)]
        nums.sort(key=lambda x:(x[0],x[1]))
        # merge intervals
        stack = []
        merged_intervals = []
        for value,btype in nums:
            if btype==0: stack += [value]
            else:
                top = stack.pop()
                if len(stack)==0:
                    merged_intervals += [Interval(top, value)]
        return merged_intervals
