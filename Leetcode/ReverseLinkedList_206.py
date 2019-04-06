# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution1(object): # Iterative
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cur = head
        prev = None
        while cur != None:
            tmp = cur.next
            cur.next = prev
            prev = cur
            cur = tmp
        return prev

class Solution2(object): # Recursive
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None: return None
        last, head = self.reverse(head)
        last.next = None # finished reverse
        return head
    def reverse(self, cur):
        if cur.next == None: return cur, cur
        last, head = self.reverse(cur.next)
        last.next = cur
        return cur, head

class Solution3(object): # Simplify Solution2 since last=cur.next
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None or (head!=None and head.next==None): return head
        rev_head = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return rev_head
