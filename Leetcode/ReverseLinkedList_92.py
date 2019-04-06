# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution1(object): # iterative
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        cur_idx = 1
        rev_st, rev_ed = None, None
        st_prev = head
        cur, prev, tmp = head, None, None
        while cur != None:
            tmp = cur.next
            if cur_idx == m: # start reverse
                rev_st = cur
                st_prev = prev
            elif cur_idx>m and cur_idx<=n:
                if st_prev != None: st_prev.next = cur
                else: head = cur
                rev_st.next = cur.next
                cur.next = prev
            prev = cur
            cur = tmp
            cur_idx += 1
        return head

class Solution2(object): # recursive
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        dump = ListNode(None)
        dump.next = head
        nxt, ed = self.Backtrack(dump, m, n, 0)
        return nxt.next

    def Backtrack(self, cur, m, n, idx):
        if cur==None:
            return None, None
        nxt, ed = self.Backtrack(cur.next, m, n, idx+1)
        if idx>=m and idx<n:
            cur.next.next = cur
            cur.next = nxt
            return nxt, ed
        if idx==m-1:
            cur.next = ed
        if idx==n:
            return nxt, cur
        return cur, ed
