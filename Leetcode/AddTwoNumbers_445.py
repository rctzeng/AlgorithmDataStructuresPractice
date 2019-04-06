# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution1(object):
    """
    If allowed to reverse digits,
     - use stack to reverse digits
     - add big numbers

    Complexity
     - Time: O(N)
     - Space: O(N)
    """
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # reverse digit
        stack1, stack2 = [], []
        while l1!=None:
            stack1.insert(0, l1.val)
            l1 = l1.next
        while l2!=None:
            stack2.insert(0, l2.val)
            l2 = l2.next
        # add big numbers
        stack, c = [], 0
        while len(stack1)>0 or len(stack2)>0:
            x1 = stack1.pop(0) if len(stack1)>0 else 0
            x2 = stack2.pop(0) if len(stack2)>0 else 0
            x = x1+x2+c
            stack.insert(0, x%10)
            c = x/10
        if c>0: stack.insert(0, c)
        # reverse digit
        rst = ListNode(None)
        cur = rst
        while len(stack)>0:
            new = ListNode(stack.pop(0))
            cur.next = new
            cur = new
        return rst.next

class Solution2(object):
    """
    If not allowed to reverse digits -> Backtrack+Pruning
     - at each dimension, iterate over all choices:
       (1) two digit align (2) 2nd digit missing (3) 1st digit missing
     - prune branches with recursive level > max_digit
    """
    def __init__(self):
        self.max_digit = None

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        nxt, _ = self.Backtrack(l1, l2, 0)
        if nxt.val/10>0:
            new = ListNode(nxt.val/10)
            new.next = nxt
            nxt.val %= 10
        else: new = nxt
        return new

    def Backtrack(self, l1, l2, digit):
        # prune
        if self.max_digit!=None and digit>self.max_digit: return None, None
        if l1==None or l2==None: return None, None
        # check if aligned -> return
        if l1.next==None and l2.next==None:
            new = ListNode(l1.val+l2.val)
            self.max_digit = digit
            return new, 1
        # each dimensiion has 3 choices
        # choice 1: l1, l2 aligned
        nxt, p = self.Backtrack(l1.next, l2.next, digit+1)
        if nxt != None and p==1:
            new = ListNode(l1.val+l2.val+(nxt.val/10))
            new.next = nxt
            nxt.val %= 10
            return new, 1
        # choice 2: l1.next, aligned with l2
        nxt, p = self.Backtrack(l1.next, l2, digit+1)
        if nxt != None and (p==1 or p==2):
            new = ListNode(l1.val+(nxt.val/10))
            new.next = nxt
            nxt.val %= 10
            return new, 2
        # choice 3: l1 aligned with l2.next
        nxt, p = self.Backtrack(l1, l2.next, digit+1)
        if nxt != None and (p==1 or p==3):
            new = ListNode(l2.val+(nxt.val/10))
            new.next = nxt
            nxt.val %= 10
            return new, 3
        return None, None
