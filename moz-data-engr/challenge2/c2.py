import sys
import os

# compress a string like this:
# aaaaabbbbbbbbbccccpqrstuv
# to this:
# a5b9c4pqrstuv

def compress(s):
    r = ""
    i = 0
    j = 0
    l = len(s)
    while i < l:
        while (j < l) and (s[i] == s[j]):
            j += 1
        if j-i > 1:
            r += s[i] + str(j-i)
        else:
            r += s[i]
        i = j

    return r

_str = raw_input()

print compress(_str)
