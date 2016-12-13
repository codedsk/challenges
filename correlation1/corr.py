# https://www.hackerrank.com/challenges/correlation-and-regression-lines-6
#
# we could put columns in a dataframe and use the Series' corr() function,
# setting the 'method' parameter to 'person':
#
# r = df['History Scores'].corr(df['Physics Scores'],method='person')
#
# calculating the person correlation coefficient is described here:
# http://www.statisticshowto.com/how-to-compute-pearsons-correlation-coefficients/


import pandas as pd
import pytest

def pearson_correlation(d,x,y):
    d['xy'] = d[x] * d[y]
    d['x2'] = pow(d[x],2)
    d['y2'] = pow(d[y],2)

    n = len(d[x])
    sxy = d['xy'].sum()
    sx = d[x].sum()
    sy = d[y].sum()
    sx2 = d['x2'].sum()
    sy2 = d['y2'].sum()

    top = (n*sxy) - (sx*sy)
    mid = ((n*sx2)-pow(sx,2))*((n*sy2)-pow(sy,2))
    bot = pow(mid,0.5)

    return 1.0*top/bot


def test_pc_1():
    df = pd.DataFrame({
            'age' : [43,21,25,42,57,59],
            'glucose' : [99,65,79,75,87,81]})
    r = pearson_correlation(df,'age','glucose')
    assert round(r,6) == 0.529809


def pearson_correlation_2(x,y):
    """incase pandas library is not allowed"""

    xy = []
    x2 = []
    y2 = []
    for i,j in zip(x,y):
        xy.append(i*j)
        x2.append(pow(i,2))
        y2.append(pow(j,2))

    n = len(x)
    sxy = sum(xy)
    sx = sum(x)
    sy = sum(y)
    sx2 = sum(x2)
    sy2 = sum(y2)

    top = (n*sxy) - (sx*sy)
    mid = ((n*sx2)-pow(sx,2))*((n*sy2)-pow(sy,2))
    bot = pow(mid,0.5)

    return 1.0*top/bot


if __name__ == "__main__":

#    df = pd.DataFrame({
#            'Physics Scores' : [15,12,8,8,7,7,7,6,5,3],
#            'History Scores' : [10,25,17,11,13,17,20,13,9,15]})
#
#    r = pearson_correlation(df,'Physics Scores','History Scores')

    p = [15,12,8,8,7,7,7,6,5,3]
    h = [10,25,17,11,13,17,20,13,9,15]

    r = pearson_correlation_2(p,h)

    print "{0:.3f}".format(r)
