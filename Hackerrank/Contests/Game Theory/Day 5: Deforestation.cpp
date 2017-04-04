#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define sc(x) scanf("%d",&(x))
#define fori(x) for(int i=0;i<x;i++)
#define forj(x) for(int j=0;j<x;j++)
#define fork(x) for(int k=0;k<x;k++)
#define repi(a,b) for(int i=a;i<=b;i++)
#define repj(a,b) for(int j=a;j<=b;j++)
const int N = 501;

int a[N][N];
int g[N];
int vis[N];

void init(int n){
	fori(n+1){
		g[i] = -1;
		vis[i] = 0;
		forj(n+1){
			a[i][j]=0;
		}
	}
}

int dfs(int x,int n){
	//cout << "x " << x << endl;
	if (g[x] == -1){
		vis[x] = 1;
		int sol = 0;
		repi(1,n){
			if (a[x][i] == 1 && vis[i]==0){
				sol ^= dfs(i,n);
			}
		}
		g[x] = sol + 1;
		return g[x];
	}
	else{
		return g[x];
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){
		int n;
		sc(n);
		
		init(n);
		fori(n-1){
			int x, y;
			sc(x); sc(y);
			a[x][y] = 1;
			a[y][x] = 1;
		}
		int sol=dfs(1,n);
		sol--;
		// fori(n+1){
		// 	cout << g[i] << " ";
		// }
		// cout << endl;
		if (sol == 0)cout << "Bob" << endl;
		else cout << "Alice" << endl;
	}
}
