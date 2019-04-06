class Solution1(object):
    """
    Divide-and-Conquer approach by modifying MergeSort: add O(N) sum checking to the merge routine
    At each ModifiedMergeSort(array) calls
     1. divide into left&right subarrays and call ModifiedMergeSort -> returns sorted&compared left&right subarrays
     2. merge sorted subarrays in O(N) -> get sorted subarray
     3. compare sorted subarrays by 2 recursors:
      - one for left subarray goes from smallest to largest element
      - another for right subarray goes from largest to smallest
      => check if left[l]+right[r]==target, and update corresponding cursors

    Complexity
     - Time: O(N log N)
     - Space: O(N)
    """
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        flag, a1, a2, sortedidx = self.ModifiedMergeSort(nums, target)
        return a1, a2
    def ModifiedMergeSort(self, nums, target):
        if len(nums)==1:
            return False, -1, -1, [0]
        # divide
        m = len(nums)/2
        left, right = nums[:m], nums[m:]
        lflag, a1, a2, sortedleftidx = self.ModifiedMergeSort(left, target) # sorted&compared
        rflag, a3, a4, sortedrightidx = self.ModifiedMergeSort(right, target) # sorted&compared
        # sort
        sortedidx = []
        l, r = 0, 0
        while l<len(left) and r<len(right):
            lidx, ridx = sortedleftidx[l], sortedrightidx[r]+len(left)
            if nums[lidx]<nums[ridx]:
                sortedidx.append(lidx)
                l += 1
            else:
                sortedidx.append(ridx)
                r += 1
        if l!=len(left): sortedidx += sortedleftidx[l:]
        if r!=len(right): sortedidx += [len(left)+x for x in sortedrightidx[r:]]

        if lflag==True: return True, a1, a2, sortedidx
        if rflag==True: return True, a3+len(left), a4+len(left), sortedidx
        # compare
        l, r = 0, len(sortedrightidx)-1
        while l<len(left) and r>=0:
            lidx, ridx = sortedleftidx[l], sortedrightidx[r]+len(left)
            x = nums[lidx]+nums[ridx]
            if x>target: r-=1
            elif x<target: l+=1
            else: return True, lidx, ridx, sortedidx
        return False, -1, -1, sortedidx
class Solution2(object):
    """
    Polish Solution1 by extracting the key idea:
        once the array is sorted, just need O(N) to find elements that sum to the target
    """
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        numsWithIdx = [(x,i) for i,x in enumerate(nums)]
        numsWithIdx.sort(key=lambda x:x[0])
        l, r = 0, len(nums)-1
        while l<r:
            x = numsWithIdx[l][0]+numsWithIdx[r][0]
            if x>target: r-=1
            elif x<target: l+=1
            else: return numsWithIdx[l][1], numsWithIdx[r][1]
class Solution3(object):
    """
    Trade space for time using data structure
     - small range -> binary array with index
     - large range -> hash
    """
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        idxmap = {nums[0]:0}
        for i in range(1,len(nums)):
            x = target-nums[i]
            if x in idxmap.keys():
                return idxmap[x], i
            idxmap[nums[i]] = i
