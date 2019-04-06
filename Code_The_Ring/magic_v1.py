import sys, math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

magicPhrase = raw_input()

def inv(x, l):
    return l-x


def dist(a, b, l):
    x1 = a-b
    x2 = a+inv(b, l)
    x3 = inv(a, l)+b
    m = min(abs(x1), x2, x3)
    if m == 0:
        return 0, 0
    if abs(x1) == m:
        if x1 > 0:
            return m, -1
        else:
            return m, 1
    if x2 == m:
        return m, -1
    return m, 1


def label(a):
    if a == ' ':
        return 0
    return ord(a)-ord('A')+1


def genInstr(dis, drc, tp):
    if drc == 0:
        return ''
    if tp == 1:
        if drc == 1:
            return '+' * dis
        return '-' * dis
    if drc == 1:
        return '>' * dis
    return '<' * dis


def greedy(spell):
    instr = ""
    cur_zone = 0
    zone = [0 for x in range(30)]
    for i in range(len(spell)):
        seq = ""
        best = 500
        move_index = cur_zone
        for j in range(30):
            zdis, zdrc = dist(cur_zone, j, 30)
            rdis, rdrc = dist(zone[j], label(spell[i]), 27)
            if zdis+rdis < best:
                seq = genInstr(zdis, zdrc, -1) + genInstr(rdis, rdrc, 1)
                best = zdis + rdis
                move_index = j
        cur_zone = move_index
        zone[cur_zone] = label(spell[i])
        instr += seq + "."
    return instr
    
print greedy(magicPhrase)
