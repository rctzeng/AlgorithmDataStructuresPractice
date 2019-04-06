G, N = {}, None
def DFS(x, y, path):
    if x==N-1 and y==N-1: # termination
        return path
    cur = x+y*N
    ex, ey, sx, sy = x+1, y, x, y+1
    E, S = ex+ey*N, sx+sy*N
    if x!=N-1 and ((cur not in G.keys()) or (cur in G.keys() and G[cur]!=E)): # move east
        C1 = DFS(ex, ey, path+'E')
        if C1!=None: return C1
    if y!=N-1 and ((cur not in G.keys()) or (cur in G.keys() and G[cur]!=S)): # move south
        C2 = DFS(sx, sy, path+'S')
        if C2!=None: return C2
    return None # no solution

T = int(input())
for t in range(1,T+1):
    N = int(input())
    P = input()
    # build path of the rival
    G, x, y = {}, 0, 0
    for p in P:
        if p=='E':
            nx, ny = x+1, y
            G[x+y*N] = nx+ny*N
            x, y = nx, ny
        if p=='S':
            nx, ny = x, y+1
            G[x+y*N] = nx+ny*N
            x, y = nx, ny
    ans = DFS(0, 0, '')
    print('Case #{}: {}'.format(t, ans))
