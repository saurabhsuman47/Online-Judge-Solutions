# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
from collections import Counter
n, k = raw_input().split()
n = int(n)
k = int(k)
nlist = []
nlist = map(int, raw_input().split())
nlist = [i%k for i in nlist]
cnt = Counter()
for i in nlist:
    cnt[i] += 1
count = 0
if cnt[0] > 0:
    count += 1
if k % 2 == 0 and cnt[k/2] > 0:
    count += 1
for i in range(1, (k-1)/2 + 1):
    count += max(cnt[i], cnt[k-i])

print count
