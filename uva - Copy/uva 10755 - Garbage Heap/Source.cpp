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
#define repk(a,b) for(int k=a;k<=b;k++)

const ll mod = 1000000007ll;
const ll inf = 1000000000000000ll;
const int N = 22;

ll a[N][N][N];
ll dp[N][N][N];

int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int zz = 1; zz <= t; zz++){
		int x, y, z;
		sc(x); sc(y); sc(z);
		fori(x){
			forj(y){
				fork(z){
					scl(a[i+1][j+1][k+1]);
				}
			}
		}

		fori(x){
			forj(y){
				fork(z){
					
					dp[i + 1][j + 1][k + 1] = (dp[i + 1][j][k + 1] + dp[i + 1][j + 1][k] + a[i + 1][j + 1][k + 1] - dp[i + 1][j][k]);
				}
			}
		}
	
		ll gmax = -1*inf;
		forj(y){
			fork(z){
				for (int jj = j+1; jj <= y; jj++){
					for (int kk = k+1; kk <= z; kk++){
						ll sum = 0;
						repi(1, x){
							ll t1 = dp[i][jj][kk] + dp[i][j][k] - dp[i][jj][k] - dp[i][j][kk];
							sum += t1;
							gmax = max(gmax, sum);
							if (sum < 0)sum = 0;
						}
					}
				}
			}
		}

		printf("%lld\n", gmax);
		if (zz != t)cout << endl;	

	}
}