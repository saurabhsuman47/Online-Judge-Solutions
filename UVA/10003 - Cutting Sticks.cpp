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
const int N = 55;
int a[N];
int dp[N][N];

int cutting_cost(int l, int r){
	if (l == r){
		return 0;
	}
	if (dp[l][r] != -1)return dp[l][r];
	int result = inf;
	repi(l, r - 1){
		result = min(result, (cutting_cost(l, i) + cutting_cost(i + 1, r) +  a[r + 1] - a[l]));
	}
	return dp[l][r] = result;
}

int main(){
	//freopen("input.txt", "r", stdin);
	while (1){
		int l,n;
		sc(l);
		if (l == 0)break;
		sc(n);
		a[0] = 0;
		fori(n){
			sc(a[i + 1]);
		}		
		a[n + 1] = l;
		fori(n + 1)forj(n + 1)dp[i][j] = -1;
		printf("The minimum cutting is %d.\n",cutting_cost(0, n));

	}
}