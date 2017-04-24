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


const int inf = 1000000000;
const int N = 100005;

ll dp[205][15][25];
int a[205];
int b[205];

void init(int mod){
	fori(205){
		forj(15){
			fork(25){
				dp[i][j][k] = -1;
			}
		}
	}
	fori(205){
		b[i] = a[i] % mod;
	}
}

ll foo(int n, int m, int sum,int mod){
	if (m == 0 && sum%mod == 0)return 1;
	if (m == 0 && sum%mod != 0)return 0;
	if (n == -1)return 0;
	if (dp[n][m][sum] != -1)return dp[n][m][sum];

	int nsum = (sum - b[n] + mod) % mod;
	return dp[n][m][sum] = (foo(n - 1, m - 1, nsum, mod) + foo(n - 1, m, sum, mod));

}

int main(){
	//freopen("input.txt", "r", stdin);
	int n, q,i = 1;
	while (true){
		sc(n); sc(q);
		if (n == 0 && q == 0)break;
		fori(n){
			sc(a[i]);
		}
		printf("Case #%d:\n",i);
		i++;
		fori(q){
			int d, m;
			sc(d); sc(m);
			init(d);
			ll t1 = foo(n-1, m, 0,d);
			printf("QUERY %d: %lld\n", i + 1, t1);
		}

	}
}