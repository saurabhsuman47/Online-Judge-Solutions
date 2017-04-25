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
#define repi(a,b) for(int i=a;i<=b;i++)
#define repj(a,b) for(int j=a;j<=b;j++)
const int N = 100005;

ll x[N], y[N];
ll mat[3][3];

ll ncr(ll n,ll r){
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
	freopen("output.txt", "w", stdout);
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){
		int n,A, B, C, D, x0, y1,M;
		cin >> n >> A >> B >> C >> D >> x[0]>> y[0]>> M;
		repi(1, n - 1){
			x[i] = (A*x[i - 1] + B) % M;
			y[i] = (C*y[i - 1] + D) % M;
		}
		/*fori(n){
			cout << x[i] << " " << y[i] << endl;
		}*/
		fori(3)forj(3)mat[i][j] = 0;
		fori(n){
			x[i] = x[i] % 3;
			y[i] = y[i] % 3;
			mat[x[i]][y[i]]++;
		}

		/*fori(n){
			cout << x[i] << " " << y[i] << endl;
		}
		fori(3){
			forj(3){
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}*/
		ll sol = 0;
		fori(3){
			forj(3){
				sol += ncr(mat[i][j], 3);
			}
			ll t1 = 1;
			forj(3){
				t1 *= ncr(mat[i][j], 1);
			}
			sol += t1;
		}
		//cout << sol << endl;
		fori(3){
			ll t1 = 1;
			forj(3){
				t1 *= ncr(mat[j][i], 1);
			}
			sol += t1;
			
			
		}
		int a[3] = { 0, 1, 2 };
		int b[3] = { 0, 1, 2 };
		do{
			//forj(3)cout << a[j] << " "; 
			ll t1 = 1;
			forj(3){
				t1 *= ncr(mat[b[j]][a[j]], 1);
			}
			//cout << t1 << endl;
			sol += t1;

		} while (next_permutation(a, a + 3));
		cout << "Case #" << z << ": " << sol << endl;
		


	}
}
