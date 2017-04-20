# Enter your code here. Read input from STDIN. Print output to STDOUT
k = int(raw_input().strip())
n = int(raw_input().strip())
nlist = map(int, raw_input().strip().split())

start = 0
end = len(nlist) - 1
while(start <= end):
    mid = (start + end)/2
    if nlist[mid] == k :
        print mid
        break
    elif nlist[mid] < k:
            start = mid + 1
    else:
        end = mid - 1
