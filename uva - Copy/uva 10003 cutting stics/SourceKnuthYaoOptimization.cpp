#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define fori(x) for(int i=0;i<x;i++)
#define forj(x) for(int j=0;j<x;j++)
#define fork(x) for(int k=0;k<x;k++)
#define repi(a,b) for(int i=a;i<=b;i++)
#define repj(a,b) for(int j=a;j<=b;j++)

const int inf = 1000000000;
const int N = 55;
int a[N];
int dp[N][N];
int p[N][N];

void bottomupdp(int n){
	int i = 0, j = 0;
	while (j <= n){
		int ii = i, jj = j;
		while (jj <= n){
			if (ii == jj)dp[ii][jj] = 0;
			else if ((ii + 1) == jj){ dp[ii][jj] = a[jj + 1] - a[ii]; p[ii][jj] = ii; }
			else{
				int t1 = p[ii][jj - 1];
				int t2 = p[ii + 1][jj];
				
				int result = inf;
				for (int k = t1; k <= t2; k++){
					int t3 = (dp[ii][k] + dp[k + 1][jj] + a[jj + 1] - a[ii]);
					if (t3 < result){
						result = t3;
						p[ii][jj] = k;
					}
					dp[ii][jj] = result;
				}				
			}
			ii++;
			jj++;
		}
		j++;
	}
}

int main(){
	
	while (1){
		int l, n;
		sc(l);
		if (l == 0)break;
		sc(n);
		a[0] = 0;
		fori(n){
			sc(a[i + 1]);
		}
		a[n + 1] = l;
		fori(n + 1)forj(n + 1)dp[i][j] = -1;
		bottomupdp(n);
		printf("The minimum cutting is %d.\n", dp[0][n]);		

	}
}