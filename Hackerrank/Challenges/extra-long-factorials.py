#!/bin/python

import sys


n = int(raw_input().strip())
fn = 1;
for i in range(1, n+1):
    fn *= i;
print fn
