class Solution(object):
    """
    Find k-th element in nums1+nums2
     - consider the k/2-th element in nums1 and nums2
     - if nums1[k/2]>nums2[k/2]: find k/2-th element in (nums1[:k/2], nums2[k/2:])
     - else: find k/2-th element in (nums1[k/2:], nums2[:k/2]) # nums1[k/2]<=nums2[k/2]
    """
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l = len(nums1)+len(nums2)
        if l%2: return self.findKth(nums1, nums2, l/2)
        else: return (self.findKth(nums1, nums2, l/2-1)+self.findKth(nums1, nums2, l/2))/2.0

    def findKth(self, A, B, k):
        # boundary cases
        if len(A)==0: return B[k]
        if len(B)==0: return A[k]
        if k==0: return min(A[0],B[0])
        if k==1: return self.findKth(A[1:],B, 0) if A[0]<B[0] else self.findKth(A,B[1:], 0)
        if len(A)==1: return self.findKth(A[1:],B,k-1) if A[0]<B[0] else self.findKth(A,B[1:],k-1)
        if len(B)==1: return self.findKth(A,B[1:],k-1) if A[0]>B[0] else self.findKth(A[1:],B,k-1)
        la, lb, m = len(A), len(B), k/2
        m1, m2 = m if la>m else la/2, m if lb>m else lb/2
        if A[m1]>B[m2]: return self.findKth(A[:k-m2],B[m2:],k-m2)
        else: return self.findKth(A[m1:],B[:k-m1],k-m1)
