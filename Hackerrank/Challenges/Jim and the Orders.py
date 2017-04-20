# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(raw_input().strip())
a = []
b = []
for i in range(n):
    t, d = map(int, raw_input().strip().split())
    a.append(i+1)
    b.append(t+d)

ba = sorted(zip(b,a))
a = [a for b,a in ba]
for item in a:
    print item,
