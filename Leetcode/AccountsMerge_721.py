class TLEAttempt(object):
    """
    Naive DFS: O(N^2)
    """
    def accountsMerge(self, accounts):
        """
        :type accounts: List[List[str]]
        :rtype: List[List[str]]
        """
        return self.DFS(accounts)

    def DFS(self, accounts):
        N = len(accounts)
        for i in range(N):
            if len(accounts[i])==1: continue
            for j in range(i+1, N):
                if len(accounts[j])==1: continue
                if accounts[i][0]==accounts[j][0]: # same name
                    for e in accounts[j][1:]:
                        if e in accounts[i][1:]: # same email
                            accounts[i]+=accounts[j][1:]
                            accounts[i]=self.Dedupe(accounts[i])
                            accounts[j]=accounts[j][:1]
        rst = []
        for i in range(N):
            if len(accounts[i])>1:
                rst += [self.Dedupe(accounts[i])]
        if len(rst)<N: return self.DFS(rst)
        return rst

    def Dedupe(self, x):
        return x[:1]+sorted(list(set(x[1:])))
