#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define fori(x) for(int i=0;i<x;i++)
#define forj(x) for(int j=0;j<x;j++)
#define fork(x) for(int k=0;k<x;k++)
#define repi(a,b) for(int i=a;i<=b;i++)
#define repj(a,b) for(int j=a;j<=b;j++)

const ll mod = 1000000007ll;
const int inf = 1000000000;
const int N = 1005;

int a[10][N];
int dp[10][N];

void init(int n){
	fori(10){
		forj(n + 1){
			dp[i][j] = -1;
		}
	}
}

int foo(int h, int d){
	if (h == 0 && d == 0){
		return 0;
	}
	if (d == 0 || h < 0 || h>9){
		return inf;
	}
	if (dp[h][d] != -1)return dp[h][d];
	return dp[h][d] = min(min((foo(h, d - 1) + 30 + a[h][d]), (foo(h - 1, d - 1) + 60 + a[h - 1][d])), (foo(h + 1, d - 1) + 20 + a[h + 1][d]));
}


int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int zz = 1; zz <= t; zz++){
		int n;
		sc(n);
		n /= 100;
		
		for (int i = 9; i >= 0; i--){
			repj(1, n){
				sc(a[i][j]);
				a[i][j] *= -1;
			}
		}
		init(n);
		int t1 = foo(0, n);
		printf("%d\n\n", t1);
	}
}