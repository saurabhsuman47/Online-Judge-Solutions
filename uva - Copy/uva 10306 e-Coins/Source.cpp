#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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

pii a[N];
int dp[41][301][301];

void init(int n){
	fori(n){
		forj(301){
			fork(301){
				dp[i][j][k] = -1;
			}
		}
	}
}

int foo(int idx, pii p1){
	if (p1.first < 0 || p1.second < 0)return inf;
	if (idx == -1){
		if (p1.first == 0 && p1.second == 0)return 0;
		else return inf;
	}
	if (dp[idx][p1.first][p1.second] != -1)return dp[idx][p1.first][p1.second];

	int t1 = foo(idx - 1, p1);
	int t2 = foo(idx, make_pair(p1.first - a[idx].first, p1.second - a[idx].second));
	
	return dp[idx][p1.first][p1.second] = min(t1, 1 + t2);
}

int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int zz = 1; zz <= t; zz++){
		int n, sum = 0;
		sc(n); sc(sum);
		fori(n){
			int t1, t2;
			sc(t1); sc(t2);
			a[i] = make_pair(t1, t2);
		}
		/*fori(n){
			cout << a[i].first << " " << a[i].second << endl;
		}*/
		init(n);
		int gmin = inf;
		repi(0, sum){
			int t1 = sum*sum - i*i;
			float t2 = sqrt(1.0*t1);
			float t3 = floor(t2);
			if (t2 != t3)continue;
			
			int ma = i, mb = (int)t2;
			//cout << ma << " - " << mb << endl;

			gmin = min(gmin,foo(n-1, make_pair(ma, mb)));
			
		}
		if (gmin > 10000){
			printf("not possible\n");
		}
		else printf("%d\n", gmin);
	}
}