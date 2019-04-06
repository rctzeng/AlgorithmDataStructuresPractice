# cover consequent duplicate case


def inv(x, l):
    return l-x

def dist(a, b, l):
    x1, x2, x3 = a-b, a+inv(b, l), inv(a, l)+b
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


def rev_label(num):
    if num == 0:
        return ' '
    return chr(num+ord('A')-1)


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


def count_dir(src, target):
    # countdown
    dns, dnc = dist(src, target, 27)
    # countup
    ups, upc = dist(src, inv(target, 27), 27)
    if dns+dnc < ups+upc:
        return dns, dnc, 1
    return ups, upc, -1


# preprocess spell to find consequentive pattern
def find_repeat(spell_num, start, rst, sum_dup):
    if start >= len(spell_num):
        return rst, sum_dup
    best = 0
    dup = False
    # try out all length
    for l in range(1, 15):
        if start+l <= len(spell_num):
            ptn = spell_num[start:start+l]
            i, times = start+l, 0
            trst = rst.copy()
            while i+l <= len(spell_num):
                if ptn == spell_num[i:i+l]:
                    times += 1
                    i += l
                else:
                    break
            if times > 0:
                dup = True
                trst.update({start: (ptn, times)})  # index: pattern, dup_times
                ttrst, t_sum_dup = find_repeat(spell_num, start+l*times+1, trst, sum_dup+l*times)
                if t_sum_dup > best:
                    rst = ttrst
                    best = t_sum_dup
    if dup is False:
        ttrst, t_sum_dup = find_repeat(spell_num, start+1, rst.copy(), sum_dup)
        if t_sum_dup > best:
            rst = ttrst
            best = t_sum_dup
    return rst, best


def find_best_zone(zone, cur, target):
    best, move_index = 500, cur
    for j in range(30):
        zdis, zdrc = dist(cur, j, 30)
        rdis, rdrc = dist(zone[j], target, 27)
        if zdis+rdis < best:
            best = zdis + rdis
            move_index = j
            seq = genInstr(zdis, zdrc, -1) + genInstr(rdis, rdrc, 1)
    return move_index, seq


# change cur's consequentive left zones to c_target
def gen_multi(zone, cur, c_target, dup_times):
    tzone = zone[:]
    total = c_target * dup_times
    tcur = cur
    instr = ''
    for i in range(len(total)):
        tcur, seq = find_best_zone(tzone, tcur, total[i])
        instr += seq + '.'
        tzone[tcur] = total[i]
    return tcur, instr, tzone


# left timer: call spell on the back way
def left_timer(zone, cur, target, c_target):
    tzone = zone[:]
    l = len(c_target)
    tcur = cur
    instr = ''
    for i in range(l):
        x = (30-i+cur) % 30
        # move to the zone
        zdis, zdrc = dist(tcur, x, 30)
        rdis, rdrc = dist(tzone[x], c_target[i], 27)
        tcur = x
        tzone[x] = c_target[i]
        # change to ch
        instr += genInstr(zdis, zdrc, -1) + genInstr(rdis, rdrc, 1)
    # set timer
    left = (30-len(c_target)+cur) % 30
    lzs, lzc = dist(cur, left, 30)
    lrs, lrc, ldir = count_dir(zone[left], target)
    instr += "<" + genInstr(lrs, lrc, 1)
    tzone[left] = target
    # repeat
    cdir = ''
    if ldir == 1:
        cdir = '-'
    else:
        cdir = '+'
    instr += "[{}{}{}]".format('>'*l, '.<'*l, cdir)

    # after counting
    tzone[left] = 0
    return left, instr, zone


def greedy(spell):
    instr = ""
    cur_zone = 0
    zone = [0 for x in range(30)]
    spell_num = [label(x) for x in spell]
    dup_table, no_use = find_repeat(spell_num, 0, {-1: (-1, -1)}, 0)
    i = 0
    while i < len(spell_num):
        if i in dup_table:
            (dup_ch, dup_times) = dup_table[i]
            i += (1+dup_times) * len(dup_ch)
            iter_dup = dup_times+1
            while iter_dup > 0:
                if iter_dup > 26:
                    dup_times, iter_dup = iter_dup - 26, 26
                else:
                    dup_times = 0
                # use only left timer
                t_zone, seq, tzone = left_timer(zone, cur_zone, iter_dup, dup_ch)
                # not use loop
                nch_zone, nseq, ntzone = gen_multi(zone, cur_zone, dup_ch, iter_dup)
                if len(seq) < len(nseq):
                    cur_zone = t_zone
                    zone = tzone
                    instr += seq
                else:
                    cur_zone = nch_zone
                    zone = ntzone
                    instr += nseq
                iter_dup = dup_times
        else:
            # normal case
            cur_zone, seq, zone = gen_multi(zone, cur_zone, [spell_num[i]], 1)
            instr += seq
            i += 1
    return instr


def check(spell, output):
    rst = ""
    zone = [0 for x in range(30)]
    cur_zone = 0
    i, ll, = 0, 0
    while i < len(output):
        ch = output[i]
        if ch == '[':
            ll = i
            if zone[cur_zone] == 0:
                while output[i] != ']':
                    i += 1
        ch = output[i]
        if ch == ']':
            if zone[cur_zone] != 0:
                i = ll+1
        ch = output[i]
        if ch == '.':
            rst += rev_label(zone[cur_zone])
        if ch == '+':
            zone[cur_zone] = (zone[cur_zone]+1) % 27
        if ch == '-':
            zone[cur_zone] = (zone[cur_zone]+26) % 27
        if ch == '>':
            cur_zone = (cur_zone+1) % 30
        if ch == '<':
            cur_zone = (cur_zone+29) % 30
        i += 1
    if rst == spell:
        print "OK"
    else:
        print "{}\n{}".format(spell, rst)


# magicPhrase = raw_input()
spell = "MELLON MORIAMORIA MELLON MELLON MORIA"
out = greedy(spell)
print out
check(spell, out)
rst, times = find_repeat([label(x) for x in spell], 0, {-1: (-1, -1)}, 0)
print rst
