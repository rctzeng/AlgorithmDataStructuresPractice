import sys, math

# cover consequent single duplicate

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


def find_best_zone(spell, zone, cur, target):
    best, move_index = 500, cur
    for j in range(30):
        zdis, zdrc = dist(cur, j, 30)
        rdis, rdrc = dist(zone[j], target, 27)
        if zdis+rdis < best:
            best = zdis + rdis
            move_index = j
            seq = genInstr(zdis, zdrc, -1) + genInstr(rdis, rdrc, 1)
    return move_index, seq, best


def count_dir(src, target):
    # countdown
    dns, dnc = dist(src, target, 27)
    # countup
    ups, upc = dist(src, inv(target, 27), 27)
    if dns+dnc < ups+upc:
        return dns, dnc, 1
    return ups, upc, -1


def find_best_timer(spell, zone, cur, target, c_target):
    dup_times = target
    if target > 26:
        dup_times, target = target - 26, 26
    else:
        dup_times = 0
    best = 500
    timer_index = ch_index = cur
    rst = ""
    # find adjacent timer
    for j in range(30):
        seq = ""
        # ch
        zdis, zdrc = dist(cur, j, 30)
        rdis, rdrc = dist(zone[j], c_target, 27)
        # left or right timer
        left, right = (j+29) % 30, (j+1) % 30
        lzs, lzc = dist(cur, left, 30)
        lrs, lrc, ldir = count_dir(zone[left], target)
        rzs, rzc = dist(cur, right, 30)
        rrs, rrc, rdir = count_dir(zone[right], target)
        move_ch = genInstr(zdis, zdrc, -1) + genInstr(rdis, rdrc, 1)
    # [Left timer]
        # move to ch
        seq = move_ch
        # set timer
        seq += "<" + genInstr(lrs, lrc, 1)
        # do counting
        if ldir == 1:
            seq += "[>.<-]"
        else:
            seq += "[>.<+]"
        if len(seq) < best:
            rst, best = seq, len(seq)
            timer_index, ch_index = left, j
    # [Right timer]
        # move to ch
        seq = move_ch
        # set timer
        seq += ">" + genInstr(rrs, rrc, 1)
        # do counting
        if rdir == 1:
            seq += "[<.>-]"
        else:
            seq += "[<.>+]"
        if len(seq) < best:
            rst, best = seq, len(seq)
            timer_index, ch_index = right, j
    return timer_index, ch_index, rst, dup_times


def greedy(spell):
    instr = ""
    cur_zone = 0
    zone = [0 for x in range(30)]
    dup_times = 0
    dup_ch = 0
    for i in range(len(spell)):
        tcur_zone, seq, best = find_best_zone(spell, zone, cur_zone, label(spell[i]))
        if best == 0:
            cur_zone, dup_ch = tcur_zone, label(spell[i])
            dup_times += 1
        elif dup_times != 0:
            iter_dup = dup_times
            while iter_dup > 0:
                t_zone, ch_zone, seq, dup_times = find_best_timer(spell, zone, cur_zone, iter_dup, dup_ch)
                nch_zone, nseq, best = find_best_zone(spell, zone, cur_zone, dup_ch)
                nseq += "." * (iter_dup-dup_times)
                if len(seq) < len(nseq):
                    cur_zone = t_zone
                    zone[cur_zone], zone[ch_zone] = 0, dup_ch
                    instr += seq
                else:
                    cur_zone = nch_zone
                    zone[cur_zone] = dup_ch
                    instr += nseq
                iter_dup = dup_times
            cur_zone, seq, best = find_best_zone(spell, zone, cur_zone, label(spell[i]))
            zone[cur_zone] = label(spell[i])
            instr += seq + "."
        else:
            cur_zone = tcur_zone
            zone[cur_zone] = label(spell[i])
            instr += seq + "."
    # duplicate to the end
    iter_dup = dup_times
    while iter_dup > 0:
        t_zone, ch_zone, seq, dup_times = find_best_timer(spell, zone, cur_zone, iter_dup, dup_ch)
        nch_zone, nseq, best = find_best_zone(spell, zone, cur_zone, dup_ch)
        nseq += "." * (iter_dup-dup_times)
        if len(seq) < len(nseq):
            cur_zone = t_zone
            zone[cur_zone], zone[ch_zone] = 0, dup_ch
            instr += seq
        else:
            cur_zone = nch_zone
            zone[cur_zone] = dup_ch
            instr += nseq
        iter_dup = dup_times
    return instr


def check(spell, output):
    rst = ""
    zone = [0 for x in range(30)]
    cur_zone = 0
    i, ll, lr = 0, 0, 0
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
            else:
                print "Loop Over"
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


def rev_label(num):
    if num == 0:
        return ' '
    return chr(num+ord('A')-1)

# magicPhrase = raw_input()
spell = "THREE" * 3 + "THE SHADOWS LIE" * 5
out = greedy(spell)
print out
check(spell, out)
