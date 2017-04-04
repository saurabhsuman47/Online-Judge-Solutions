#!/bin/python

import sys
import math


s = raw_input().strip()
length = len(s)
row = int(math.floor(math.sqrt(length)))
col = int(math.ceil(math.sqrt(length)))

for i in range(col):
    s1 = ""
    idx = i
    while(idx < length):
        s1 += s[idx]
        idx += col
    print s1,
