import numpy as np
import pandas as pd

pd.set_option('display.height', 1000)
pd.set_option('display.width', 1000)
pd.set_option('display.max_columns', 500)
pd.set_option('display.max_rows', 500)

def xorseq(L,R):
    result = 0
    for n in xrange(L, R+1):
        if (n-2)% 4 == 0:
            result = result ^ (n+1)
        if (n+1) % 4 == 0:
            result = result ^ 0
        if (n % 4) == 0:
            result = result ^ n
        if (n-1) % 4 == 0:
            result = result ^ 1
    return result


#Q = int(raw_input().strip())
#for a0 in xrange(Q):
#    L,R = raw_input().strip().split(' ')
#    L,R = [long(L),long(R)]
#    print(xorseq(L,R))

s = 50

arr1 = np.zeros((s,s))
arr2 = np.zeros((s,s))

for m1 in xrange(s):
    for m2 in xrange(m1,s):
        arr1[m1][m2] = xorseq(m1,m2)
        arr2[m1][m2] = m1^m2

df1 = pd.DataFrame(arr1)
df2 = pd.DataFrame(arr2)

print df1
#print xorseq(2,4)
#print xorseq(3,3)
