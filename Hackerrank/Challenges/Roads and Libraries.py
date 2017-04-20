#!/bin/python

import sys

adj_list = []
vis = []


def dfs(idx, n):
    global vis, adj_list
    vis[idx] = 1
    for i in adj_list[idx]:
        if vis[i] == 0:
            dfs(i, n)
    

q = int(raw_input().strip())
for a0 in xrange(q):
    n,m,x,y = raw_input().strip().split(' ')
    n,m,x,y = [int(n),int(m),int(x),int(y)]
    adj_list = [[] for i in range(n)]
    for a1 in xrange(m):
        city_1,city_2 = raw_input().strip().split(' ')
        city_1,city_2 = [int(city_1) - 1,int(city_2) - 1]
        adj_list[city_1].append(city_2)
        adj_list[city_2].append(city_1)
    if x <= y:
        print n*x
    else:
        vis = [0 for i in range(n)]
        count = 0       
        for i in range(n):
            if vis[i] == 0:
                flag = 0
                count += 1
                dfs(i, n)
        print count*x + (n-count)*y 

