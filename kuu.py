#!/usr/bin/python3
import sys
import itertools

word = sys.argv[1]
i=1
for p in itertools.permutations(word, len(word)):
    print("%8d" % i, ':', ''.join(p))
    i+=1
