# https://www.hackerrank.com/challenges/easy-sum

import cProfile


def easy_sum(N,m):

    # there is a pattern of mod values that will cycle
    # figure out how many full cycles we can quickly calculate
    full_cycles = N/m

    # calculate the number of incomplete, partial cycles
    partial_cycles = N%m

    # find the sum of a single cycle
    # general counting sum formula:   n   *  (n+1) / 2
    # modified for our values:      (m-1) *    m   / 2
    full_cycle_sum = m * (m-1) / 2

    partial_cycle_sum = partial_cycles * (partial_cycles+1) / 2

    s = (full_cycles * full_cycle_sum) + partial_cycle_sum

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


    # cProfile.run('easy_sum(9513183453,338422344)')
