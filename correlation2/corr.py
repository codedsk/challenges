# https://www.hackerrank.com/challenges/computing-the-correlation

import pytest

def pearson_correlation(x,y):
    n = len(x)
    sxy = 0
    sx = 0
    sy = 0
    sx2 = 0
    sy2 = 0

    for xi,yi in zip(x,y):
        sxy += xi*yi
        sx += xi
        sy += yi
        sx2 += pow(xi,2)
        sy2 += pow(yi,2)

    top = (n*sxy) - (sx*sy)
    m1 = (n*sx2) - pow(sx,2)
    m2 = (n*sy2) - pow(sy,2)
    bot = pow(m1*m2,0.5)

    r = 1.0*top/bot

    return r


def test_pc_1():
    math = [73,48,95,95,33,47,98,91,95,93,70,85,33,47,95,84,43,95,54,72]
    physics = [72,67,92,95,59,58,95,94,84,83,70,79,67,73,87,86,63,92,80,76]
    chemistry = [76,76,95,96,79,74,97,97,90,90,78,91,76,90,95,95,75,100,87,90]

    rmp = pearson_correlation(math,physics)
    rpc = pearson_correlation(physics,chemistry)
    rcm = pearson_correlation(chemistry,math)

    assert round(rmp,2) == 0.89
    assert round(rpc,2) == 0.92
    assert round(rcm,2) == 0.81


if __name__ == "__main__":
    N = int(raw_input())
    math = []
    physics = []
    chemistry = []
    for i in xrange(N):
        (m,p,c) = raw_input().split()
        math.append(int(m))
        physics.append(int(p))
        chemistry.append(int(c))

    r1 = pearson_correlation(math,physics)
    r2 = pearson_correlation(physics,chemistry)
    r3 = pearson_correlation(chemistry,math)

    print "{0:.2f}\n{1:.2f}\n{2:.2f}".format(round(r1,2),round(r2,2),round(r3,2))
