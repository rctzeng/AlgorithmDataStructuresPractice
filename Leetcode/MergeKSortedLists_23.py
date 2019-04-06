# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution1(object):
    """
    O(K max(list_length))
    """
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        new_head = ListNode(-1)
        cur = new_head
        while True:
            # find min
            min_idx, min_value = -1, None
            for i,l in enumerate(lists):
                if l==None: continue
                if min_value==None or l.val<min_value:
                    min_idx, min_value = i, l.val
            if min_idx==-1: break # all nodes extracted
            # extract
            cur.next = ListNode(min_value)
            cur = cur.next
            lists[min_idx] = lists[min_idx].next
        return new_head.next

class Solution2(object):
    """
    Divide & Conquer: O(N log K)
    """
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if len(lists)==0: return []
        if len(lists)==1: return lists[0]
        m = len(lists)/2
        left = self.mergeKLists(lists[:m])
        right = self.mergeKLists(lists[m:])
        return self.merge2Lists(left, right)

    def merge2Lists(self, left, right):
        new_head = ListNode(-1)
        cur = new_head
        while left!=None or right!=None:
            if right==None or (left!=None and right!=None and left.val<right.val):
                cur.next = ListNode(left.val)
                left = left.next
            else:
                cur.next = ListNode(right.val)
                right = right.next
            cur = cur.next
        return new_head.next
