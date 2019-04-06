# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        self.stat = {}
        return self.DFS(head)

    def DFS(self, cur):
        if cur==None: return None
        if cur in self.stat.keys(): return self.stat[cur]
        cpy = RandomListNode(cur.label)
        self.stat[cur] = cpy
        cpy.next = self.DFS(cur.next)
        cpy.random = self.DFS(cur.random)
        return cpy
