# categorize the line location of words in a file.

import pprint
import re

filename = "input1.txt"
linenumber = 0
d = {}

with open(filename,"r") as fp:
    for line in fp:
        linenumber += 1

        # remove punctuation
        line = re.sub(r'[.,?!]','',line)

        for word in line.strip().split():
            if not d.has_key(word):
                d[word] = []
            d[word].append(linenumber)

pprint.pprint(d)
