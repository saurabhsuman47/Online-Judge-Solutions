# Enter your code here. Read input from STDIN. Print output to STDOUT
t = int(raw_input().strip())

for z in range(t):
    n, k = map(int, raw_input().strip().split())
    a = map(int, raw_input().strip().split())
    b = map(int, raw_input().strip().split())
    a.sort()
    b.sort(reverse = True)
    flag = 0
    for i in range(n):
        if(a[i] + b[i] < k):
            flag = 1
            break
    if(flag == 0):
        print "YES"
    else:
        print "NO"
    
