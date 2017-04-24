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
const int N = 76;

int a[2 * N][2 * N];
int dp[2 * N][2 * N];

int main(){
	freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int zz = 1; zz <= t; zz++){
		int n;
		sc(n);
		repi(1,n){
			repj(1,n){
				sc(a[i][j]);
				a[i][j] *= -1;
				a[i + n][j] = a[i][j];
				a[i][j + n] = a[i][j];
				a[i + n][j + n] = a[i][j];
			}
		}

		repi(1, 2*n){
			repj(1, 2*n){
				dp[i][j] = dp[i][j - 1] + a[i][j];
			}
		}
		int gmax = -1 * inf;
		//pii p1, p2;
		repi(1, n){
			repj(i, i+n-1){
				int sum = 0;
				int total = 0;
				int tmax = -1 * inf;
				for (int k = 1; k <= n;k++){
					int t1 = dp[k][j] - dp[k][i - 1];
					sum += t1;
					total += t1;
					if (sum > tmax)tmax = sum;
					if (sum < 0){
						sum = 0;
					}
				}
				if (gmax < -1 * (total - tmax))gmax = -1 * (total - tmax);
				
			}
		}
		printf("%d\n", gmax);
		//cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
	}
}