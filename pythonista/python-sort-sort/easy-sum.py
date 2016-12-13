# https://www.hackerrank.com/challenges/easy-sum

import math
import cProfile


def easy_sum_f(N,m):

    # there is a pattern of mod values that will cycle
    # figure out how many cycles we will have
    cycles = N/m

    # find the sum of a single cycle
    # general counting sum formula: n(n+1)/2
    # modified for our values: m(m-1)/2
    cycle_sum = m * (m-1) / 2

    s = cycles * cycle_sum

    #print "cycles: %s\ncs: %s\ns %s" % (cycles, cycle_sum, s)

    return long(s)


def easy_sum(N,m):

    # there is a pattern of mod values that will cycle
    # figure out how many full cycles we can quickly calculate
    full_cycles = N/m

    # calculate the number of incomplete, partial cycles
    # this will be some value less than 1
    partial_cycles = 1.0 * (N % m) / m

    # find the sum of a single cycle
    # when m is odd, the sum of a cycle will be:
    # m*(m/2)
    halfm = m / 2L
    cycle_sum = m * halfm

    # when m is even we need to add on one more halfm
    # to account for an sum
    if (m & 1) == 0:
        cycle_sum += halfm

    s = (full_cycles + partial_cycles) * cycle_sum

    # print "full: %s\npart: %s\ncs: %s\ns %s" % (full_cycles, partial_cycles, cycle_sum, s)

    return long(s)


def get_testcase():
    # read the upper bound of the summation and the modulus for this test case
    N,m = raw_input().strip().split()
    N = long(N.strip())
    m = long(m.strip())
    return N,m


if __name__ == "__main__" :

    # read the number of test cases
    T = int(raw_input().strip())
    testcases = []
    rows = []

    for test in range(T):

        N,m = get_testcase()
        testcases.append((N,m))

    for (N,m) in testcases:
        s = easy_sum(N,m)
        print s
        s = easy_sum_f(float(N),float(m))
        print s


    cProfile.run('easy_sum(9513183453,338422344)')
    print ""
    cProfile.run('easy_sum_f(9513183453,338422344)')
