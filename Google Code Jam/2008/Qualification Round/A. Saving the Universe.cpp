#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <sstream>
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
const int N = 100005;

map<string, int> mym;
int dp[101][1005];

void init(int q,int n){
	fori(q+1){
		forj(n+1){
			if (i != 0)dp[i][j] = inf;
			else dp[i][j] = 0;
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t;
	sc(t);
	for (int zz = 1; zz <= t; zz++){
		int n,q;
		string s;
		sc(n);
		mym.clear();
		getline(cin, s);
		fori(n){
			getline(cin, s);
			//cout << s << endl;
			mym[s] = i+1;
		}
		sc(q);
		init(q,n);
		getline(cin, s);
		repi(1,q){
			getline(cin, s);
			//cout << s << endl;
			int t1 = mym[s];
			repj(1, n){
				if (t1 == j){
					dp[i][j] = inf;
					continue;
				}
				
				for (int k = 1; k <= n; k++){
					dp[i][j] = min(dp[i][j], (j == k) ? dp[i - 1][k] : dp[i - 1][k] + 1);
				}
			}
		}
		int t2 = inf;
		repi(1, n){
			t2 = min(t2, dp[q][i]);
		}

		printf("Case #%d: %d\n",zz, t2);
	}
}