class Solution(object):
    """
    DFS
     - Cut branch if ) more than (
     - Check validness by using stack
    """
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        self.s = s
        self.solutions = []
        self.max_length = 0
        self.DFS([], 0)
        # remove duplicate and select minimum removal
        self.solutions = sorted(self.solutions)
        deduped_solutions = []
        prev = None
        for sol in self.solutions:
            if sol==prev or len(sol)<self.max_length: continue
            deduped_solutions += [''.join(sol)]
            prev = sol
        return deduped_solutions

    def DFS(self, cur, level):
        # prune
        match_result = self.IsValidParentheses(cur)
        if match_result==-1: return
        if level==len(self.s):
            if match_result==0:
                if len(cur)>=self.max_length:
                    self.solutions += [cur]
                    self.max_length = max(self.max_length, len(cur))
            return
        # choices: add or not add
        self.DFS(cur+[self.s[level]], level+1) # not remove
        if self.s[level] in ['(', ')']: self.DFS(cur, level+1) # remove
        return

    def IsValidParentheses(self, s):
        stack = []
        for x in s:
            if x=='(': stack += [x]
            elif x==')':
                if len(stack)==0: return -1 # impossible solution
                stack.pop()
        if len(stack)!=0: return 1 # possible to add )
        return 0 # valid parentheses
