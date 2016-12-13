# https://www.hackerrank.com/contests/hourrank-5/challenges/xor-se

def xor_sum(L,R):
    """return the xor sum of the elements in the sequence from L to R
    """
    s = 0
    print L,R

    final_xors = []

    # 1^1 == 0
    # count the number of 1's and xor by 1 at the end if needed
    # the number of 1's is R/4
    # default to 1 for now, fix later
    final_xors.append(1)

    start = L
    stop = R+1

    # start automatic xor'ing on an even value
    if start%2 != 0:
        final_xors.append(L)
        start += 1

    # end automatic xor'ing on an even value
    # stop is even, means R is odd
    if stop%2 == 0:
        final_xors.append(R)
        stop = R

    for i in xrange(start, stop, 2):
        m = i&3
        if m == 0:
            s = s ^ i
        elif m == 2:
            s = s ^ (i+1)

    for i in final_xors:
        s = s ^ i

    return s


if __name__ == '__main__':
    Q = int(raw_input().strip())

    inputs = []

    for a0 in xrange(Q):
        L,R = raw_input().strip().split(' ')
        inputs.append([long(L),long(R)])


#    for a in xrange(Q):
#        s = xor_sum(*inputs[a])
#        print s

    for m1 in xrange(11):
        for m2 in xrange(11):
            xor_sum()
