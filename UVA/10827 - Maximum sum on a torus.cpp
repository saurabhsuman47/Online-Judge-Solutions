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
const int N = 80;

int a[N][N];
int dp[N][N];

int rsq2d(int i,int j,int ii,int jj){
	return (dp[ii][jj] + dp[i - 1][j - 1] - dp[ii][j - 1] - dp[i - 1][jj]);
}

int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int zz = 1; zz <= t; zz++){
		int n;
		sc(n);
		fori(n){
			forj(n){
				sc(a[i + 1][j + 1]);
			}
		}

		repi(1, n){
			repj(1, n){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + a[i][j] - dp[i - 1][j - 1];
			}
		}
		int gmax = -1 * inf;
		//pii p1, p2;
		repi(1, n){
			repj(1, n){
				for (int ii = 1; ii <= n; ii++){
					for (int jj = 1; jj <= n; jj++){
						int t1;
						if (ii >= i && jj >= j){
							t1 = rsq2d(i, j, ii, jj);							
						}
						else if (ii >= i && jj < j){
							t1 = rsq2d(i, j, ii, n) + rsq2d(i, 1, ii, jj);
						}
						else if(ii < i && jj >= j){
							t1 = rsq2d(i, j, n, jj) + rsq2d(1, j, ii, jj);
						}
						else{
							t1 = rsq2d(i, j, n, n) + rsq2d(1, 1, ii, jj) + rsq2d(1,j,ii,n)+ rsq2d(i,1,n,jj);
						}
						if (t1 > gmax){
							gmax = t1;
							/*p1 = make_pair(i, j);
							p2 = make_pair(ii, jj);*/
						}
					}
				}
			}
		}
		printf("%d\n", gmax);
		//cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << endl;
	}
}