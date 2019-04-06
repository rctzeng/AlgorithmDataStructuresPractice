class Solution(object):
    """
    DFS: O((len(board)!)/(len(hand)!))
    """
    def findMinStep(self, board, hand):
        """
        :type board: str
        :type hand: str
        :rtype: int
        """
        self.solution = -1
        hand_dict = {}
        for b in hand:
            hand_dict[b] = 1 if b not in hand_dict.keys() else hand_dict[b]+1
        self.DFS(board, hand_dict)
        return len(hand)-self.solution if self.solution!=-1 else -1

    def DFS(self, board, hand_dict):
        if board=='': # termination condition reached
            s = sum([v for k,v in hand_dict.items()])
            if self.solution==-1:
                self.solution=s
            self.solution = max(self.solution, s)
            return
        # scan over board to (1) inject balls in hand or (2) remove adjacent balls
        i=0
        while i<len(board):
            cur = board[i]
            st, ed = i, i
            while ed<len(board) and board[ed]==board[st]: ed+=1 # count adjacent balls from board[i]
            if ed-st>=3: # remove adjacent balls
                self.DFS(board[:st]+board[ed:], hand_dict)
                i = ed
            elif cur in hand_dict.keys() and hand_dict[cur]>0: # try to inject a ball
                if ed-st>=2: # inject 1 ball and reach condition to remove adjacent balls
                    hand_dict[cur]-=1
                    self.DFS(board[:st]+board[ed:], hand_dict)
                    hand_dict[cur]+=1
                else: # inject 1 ball
                    hand_dict[cur]-=1
                    self.DFS(board[:i]+cur+board[i:], hand_dict)
                    hand_dict[cur]+=1
                i = ed
            else: i+=1
        return
