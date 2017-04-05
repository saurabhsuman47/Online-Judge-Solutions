# Enter your code here. Read input from STDIN. Print output to STDOUT
from fractions import gcd
t = int(raw_input().strip())
for z in range(t):
    n = int(raw_input().strip())
    set1 = set(map(int, raw_input().strip().split()))
    res = 0
    for s in set1:
        res = gcd(res, s)
    if res > 1:
        print "NO"
    else :
        print "YES"