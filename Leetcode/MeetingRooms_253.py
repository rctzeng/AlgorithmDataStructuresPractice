# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    """
    Sort+HashSet
     - sort all start/end times: start goes before end if at same time
     - linear scan through the sorted times: meet start -> push, meet end -> pop
     - keep track the max number of start

    Complexity
     - Time: O(N log N)
     - Space: O(N)
    """
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        intervals = [(x.start,x.end,i) for i,x in enumerate(intervals)]
        # sort start/end times
        starts, ends = [(x[0],x[2]) for x in intervals], [(x[1],x[2]) for x in intervals]
        starts.sort(key=lambda x:x[0])
        ends.sort(key=lambda x:x[0])
        # merge to ensure start goes before end
        times, s, e = [], 0, 0
        while s<len(intervals) and e<len(intervals):
            if starts[s][0]<ends[e][0]:
                times.append(starts[s])
                s += 1
            else:
                times.append(ends[e])
                e += 1
        if s<len(intervals): times += starts[s:]
        if e<len(intervals): times += ends[e:]
        # compute max overlapped intervals
        max_intervals = 0
        Starts = set()
        for t in times:
            if t[1] not in Starts:
                Starts.add(t[1])
            else:
                Starts.remove(t[1])
            max_intervals = max(max_intervals, len(Starts))
        return max_intervals
