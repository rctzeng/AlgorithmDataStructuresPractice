# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        c1, c2, prev, carry = l1, l2, None, 0
        while c1 != None and c2 != None:
            x = c1.val+c2.val+carry
            c1.val = x%10
            carry = x/10
            prev = c1
            c1, c2 = c1.next, c2.next
        if c1 != None:
            prev.next = c1
            while c1 != None:
                x=c1.val+carry
                c1.val = x%10
                carry = x/10
                prev = c1
                c1 = c1.next
        if c2 != None:
            prev.next = c2
            while c2 != None:
                x=c2.val+carry
                c2.val = x%10
                carry = x/10
                prev = c2
                c2 = c2.next
        if carry>0:
            prev.next = ListNode(carry)
        return l1
