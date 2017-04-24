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

const int mod = 1000000;
const int inf = 1000000000;
const int N = 105;

int dp[N][N];

void init(){
	dp[0][0] = 1;
	repi(1, N-1){
		forj(N){
			/*dp[i][j] = dp[i - 1][j];
			if(j>0)dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;*/
			fork(j+1){
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
			}
		}
	}
}


int main(){
	init();
	/*fori(10){
		forj(10)cout << dp[i][j] << " "; cout << endl;
	}*/
	//freopen("input.txt", "r", stdin);
	while (1){
		int n, k;
		sc(n); sc(k);
		if (n == 0 && k == 0)break;
		printf("%d\n", dp[k][n]);
	}
}