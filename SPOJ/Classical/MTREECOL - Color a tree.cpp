#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define fori(x) for(int i=0;i<x;i++)
#define forj(x) for(int j=0;j<x;j++)
#define fork(x) for(int k=0;k<x;k++)
#define repi(a,b) for(int i=a;i<=b;i++)
#define repj(a,b) for(int j=a;j<=b;j++)

const int N = 1005;
int a[N];
int b[N];
int t[N];
int used[N];
int parent[N];
vector<int> child[N];

int main(){
	//freopen("input.txt", "r", stdin);
	while (true){
		int n, root;
		sc(n); sc(root);
		if (n == 0 && root==0)break;
		repi(1,n){
			sc(a[i]);
		}
		fori(n+1){
			child[i].clear();
			parent[i] = 0;
			b[i] = 0;
			t[i] = 1;
			used[i] = 0;
		}
		fori(n-1){
			int x, y;
			sc(x); sc(y);
			parent[y] = x;
			child[x].push_back(y);
		}
		int nodeCount = n;
		int totalCost = 0;
		int time = 1;
		while (nodeCount > 0){
			int idx;
			double costrate=0.0;
			repi(1,n){
				if (used[i] == 1)continue;
				double t1 = (a[i] * 1.0) / t[i];
				if (t1 > costrate){
					idx = i;
					costrate = t1;
				}
			}
			if (parent[idx] == 0){
				fori(child[idx].size()){
					parent[child[idx][i]] = 0;
				}
				totalCost += (a[idx]*time + b[idx]);
				time += t[idx];
			}
			else{
				int p = parent[idx];
				a[p] = a[idx] + a[p];
				b[p] = b[p] + b[idx] + a[idx] * t[p];
				t[p] = t[p] + t[idx];
				fori(child[idx].size()){
					parent[child[idx][i]] = p;
					child[p].push_back(child[idx][i]);
				}
			}
			
			used[idx] = 1;
			nodeCount--;
		}
		printf("%d\n", totalCost);




	}
}