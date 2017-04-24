#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
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
const ll inf = 100000000000;
const int N = 100005;

ll a[N];
ll b[N];
ll ilis[N];
ll dlis[N];

int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int zz = 1; zz <= t; zz++){
		int n;
		sc(n);
		fori(n)sc(a[i]);
		fori(n)sc(b[i]);
		fori(n){
			ilis[i] = -1 * inf;
			dlis[i] = -1 * inf;
		}
		fori(n){
			int flag = 0;
			forj(i){
				if (a[i] > a[j]){
					ilis[i] = max(ilis[i],ilis[j] + b[i]);
					flag = 1;
				}
			}
			if (flag == 0){
				ilis[i] = b[i];
			}
			flag = 0;
			forj(i){
				if (a[i] < a[j]){
					dlis[i] = max(dlis[i], dlis[j] + b[i]);
					flag = 1;
				}
			}
			if (flag == 0){
				dlis[i] = b[i];
			}
		}
		ll imax, dmax;
		imax = dmax = -1 * inf;
		/*fori(n){
			cout << ilis[i] << " ";
		}
		cout << endl;
		fori(n){
			cout << dlis[i] << " ";
		}
		cout << endl;*/
		fori(n){
			imax = max(imax, ilis[i]);
			dmax = max(dmax, dlis[i]);
		}
		if (imax >= dmax){
			printf("Case %d. Increasing (%lld). Decreasing (%lld).\n", zz, imax, dmax);
		}
		else{
			printf("Case %d. Decreasing (%lld). Increasing (%lld).\n", zz, dmax, imax);
		}

		

	}
}