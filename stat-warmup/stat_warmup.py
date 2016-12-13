# https://www.hackerrank.com/challenges/stat-warmup

import pytest


def mean(l):
    return 1.0*sum(l)/len(l)


def test_mean_123():
    assert mean([1,2,3]) == 2

def test_mean_1234():
    assert mean([1,2,3,4]) == 2.5

def test_mean_1():
    l = [64630, 11735, 14216, 99233, 14470, 4978, 73429, 38120, 51135, 67060]
    assert mean(l) == 43900.6


def median(l):
    l.sort()
    llen = len(l)
    isodd = llen%2
    middle = llen/2

    if isodd:
        m = l[middle]
    else:
        m = (l[middle-1] + l[middle])/ 2.0

    return m

def test_median_even_list():
    assert median([2,4,6,8]) == 5

def test_median_odd_list():
    assert median([2,4,6]) == 4

def test_median_1():
    l = [64630, 11735, 14216, 99233, 14470, 4978, 73429, 38120, 51135, 67060]
    assert median(l) == 44627.5


def mode(l):
    counts = {}
    maxcnt = 1
    maxkey = l[0]
    for k in l:
        v = counts.get(k,0)
        counts[k] = v+1
        if maxcnt < counts[k]:
            maxkey = k
            maxcnt = counts[k]
        elif maxcnt == counts[k]:
            if (k < maxkey):
                maxkey = k
    return maxkey


def test_mode_no_repeats():
    assert mode([3,1,2]) == 1

def test_mode_1_max():
    assert mode([1,2,2,3,4,4,4]) == 4

def test_mode_less_max():
    assert mode([1,2,2,2,3,4,4,4]) == 2

def test_mode_middle_max():
    assert mode([1,2,2,2,2,3,4,4,4]) == 2

def test_mode_beginning_max():
    assert mode([1,1,1,2,2,3,4,4]) == 1

def test_mode_unsorted():
    assert mode([4,1,4,1,2,1,3,1,1]) == 1

def test_mode_1():
    l = [64630, 11735, 14216, 99233, 14470, 4978, 73429, 38120, 51135, 67060]
    assert mode(l) == 4978


def stddev(l):
    m = mean(l)
    return pow(sum([pow((x-m),2) for x in l])/len(l),0.5)


def test_stddev_1():
    assert stddev([1,2,4,9,16]) == 5.5353410012392192

def test_stddev_2():
    assert stddev([1,2,3,4]) == 1.1180339887498949

def test_stddev_3():
    l = [64630, 11735, 14216, 99233, 14470, 4978, 73429, 38120, 51135, 67060]
    sd = stddev(l)
    assert round(sd,1) == 30466.9

# http://www.dummies.com/how-to/content/how-to-calculate-a-confidence-interval-for-a-popul.html

def confint(m,sd,n):
    z = 1.96
    moe = 1.0*z*sd/pow(n,0.5)
    lower_boundary = m-moe
    upper_boundary = m+moe
    return (lower_boundary, upper_boundary)

def test_confint_1():
    m = 7.5
    sd = 2.3
    n = 100
    lb,ub = confint(m,sd,n)
    assert (round(lb,2),round(ub,2)) == (7.05,7.95)

def test_confint_3():
    l = [64630, 11735, 14216, 99233, 14470, 4978, 73429, 38120, 51135, 67060]
    m = mean(l)
    sd = stddev(l)
    n = len(l)
    lb,ub = confint(m,sd,n)
    assert (round(lb,1),round(ub,1)) == (25017.0,62784.2)


if __name__ == "__main__":

    N = int(raw_input())
    l = [int(x) for x in raw_input().split()]

    m1 = mean(l)
    m2 = median(l)
    m3 = mode(l)
    sd = stddev(l)
    ci = confint(m1,sd,len(l))

    print "{0:.1f}\n{1:.1f}\n{2:d}\n{3:.1f}\n{4[0]:.1f} {4[1]:.1f}".format(m1,m2,m3,sd,ci)
