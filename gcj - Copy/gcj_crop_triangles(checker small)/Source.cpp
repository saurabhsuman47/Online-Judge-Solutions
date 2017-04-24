#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;

#define scl(x) scanf("%lld",&x)
#define sc(x) scanf("%d",&x)
#define fori(x) for(int i=0;i<x;i++)
#define forj(x) for(int j=0;j<x;j++)
#define fork(x) for(int k=0;k<x;k++)
#define repi(a,b) for(int i=a;i<=b;i++)
#define repj(a,b) for(int j=a;j<=b;j++)
const int N = 100005;

ll x[N], y[N];
ll mat[3][3];

ll ncr(ll n, ll r){
	if (r > n)return 0;
	ll result = 1;
	for (ll i = 0; i < r; i++){
		result *= (n - i);
	}
	for (ll i = 1; i <= r; i++){
		result /= i;
	}
	return result;
}
int main(){
	freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){
		int n, A, B, C, D, x0, y1, M;
		cin >> n >> A >> B >> C >> D >> x[0] >> y[0] >> M;
		repi(1, n - 1){
			x[i] = (A*x[i - 1] + B) % M;
			y[i] = (C*y[i - 1] + D) % M;
		}
		/*fori(n){
		cout << x[i] << " " << y[i] << endl;
		}*/
		ll sol = 0;
		fork(n){			
			repj(k+1,n-1){
				//if (k == j)continue;
				repi(j+1,n-1){
					//if (i==k || j == i)continue;
					ll t1 = (x[i] + x[j] + x[k]) % 3;
					ll t2 = (y[i] + y[j] + y[k]) % 3;
					if (t1 == 0 && t2 == 0)sol++;
					
					
				}
			}
		}
		cout << "Case #" << z << ": " << sol << endl;



	}
}
