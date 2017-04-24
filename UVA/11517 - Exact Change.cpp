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
const int N = 105;

int a[N];
int dp[20005][N];

void init(int t2,int n){
	fori(t2*2){
		forj(n+1){
			dp[i][j] = -1;
		}
	}
}

int foo(int money, int n){
	//cout << money << " " << n << endl;
	if (money == 0)return 0;
	if (money < 0 || n == 0)return inf;
	if (dp[money][n] != -1)return dp[money][n];
	return dp[money][n] = min(foo(money, n - 1) , 1 + foo(money - a[n - 1], n-1));
}

int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int zz = 1; zz <= t; zz++){
		int money;
		sc(money);
		int n;
		sc(n);
		int t2 = money;
		fori(n){
			sc(a[i]);
			t2 = max(t2, a[i]);
		}
		init(t2,n);
		int ii = money;
		while (true){
			int t1 = foo(ii, n);
			if (t1 < inf){
				printf("%d %d\n", ii, t1);
				break;
			}
			ii++;
		}
	}
}