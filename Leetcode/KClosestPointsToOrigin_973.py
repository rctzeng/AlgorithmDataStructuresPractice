class Solution1(object):
    """
    Sorting
     - Time: O(N log N)
     - Space: O(N)
    """
    def kClosest(self, points, K):
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        dist = [(i,x[0]*x[0]+x[1]*x[1]) for i,x in enumerate(points)]
        dist.sort(key=lambda x:x[1])
        return [points[i] for i,_ in dist[:K]]

class Solution2(object):
    """
    QuickSort
     - Time: O(N)
     - Space: O(N)
    """
    def kClosest(self, points, K):
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        self.topK = []
        self.findTopK(points, K)
        return self.topK

    def findTopK(self, points, K):
        # choose pivot: just select the 1st element // TO-DO: improve by order of statics
        pivot_idx, i = 0, 1
        pivot_dist = points[pivot_idx][0]*points[pivot_idx][0]+points[pivot_idx][1]*points[pivot_idx][1]
        while i<len(points):
            if points[i][0]*points[i][0]+points[i][1]*points[i][1] < pivot_dist:
                # swap(i,pivot) to move points[i] to smaller part
                tmp = points[i]
                points[i] = points[pivot_idx]
                points[pivot_idx] = tmp
                # swap(i,pivot+1) to remain order [<pivot|pivot|>pivot]
                tmp = points[pivot_idx+1]
                points[pivot_idx+1] = points[i]
                points[i] = tmp
                pivot_idx += 1
            i += 1
        if pivot_idx<K:
            self.topK += points[:pivot_idx+1]
            if K-pivot_idx-1>0: self.findTopK(points[pivot_idx+1:], K-pivot_idx-1)
        else: self.findTopK(points[:pivot_idx+1], K)
