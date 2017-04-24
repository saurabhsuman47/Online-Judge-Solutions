#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;

#define scl(x) scanf("%lld",&x)
#define sc(x) scanf("%d",&x)
#define fori(x) for(ll i=0;i<x;i++)
#define forj(x) for(ll j=0;j<x;j++)
#define repi(a,b) for(ll i=a;i<=b;i++)
#define repj(a,b) for(ll j=a;j<=b;j++)
const ll n = 1000000;

ll a[1000005];
vector <ll> myv;
set<ll> mys;
void seive(){
	repi(2, 1000){
		if (a[i] == 0){
			//cout << "i " << i << endl;
			for (ll j = i; j*i <= n; j++){
				a[i*j] = 1;
			}
		}
	}
	repi(2, n)if (a[i] == 0)myv.push_back(i);
}

ll parent(ll x, ll l){
	while (a[x - l] != x){
		a[x - l] = a[a[x - l] - l];
		x = a[x - l];
	}
	return a[x - l];
}
void merge(ll x, ll y, ll l){
	ll t1 = parent(x, l);
	ll t2 = parent(y, l);
	if (t1 != t2){
		a[t1 - l] = t2;
	}
	return;
}



int main(){
	seive();
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){
		ll l, r, p;
		scl(l); scl(r); scl(p);
		repi(l, r){
			a[i - l] = (ll)i;
		}
		fori(myv.size()){
			if (myv[i] < p)continue;
			ll t1 = myv[i];
			if (t1 > (r - l + 1))break;
			int flag = 0;
			ll t2 = 0;
			ll j = l;
			if (l%t1 != 0){
				ll k1 = (l / t1);
				j = (k1 + 1)*t1;
			}
			while (j <= r){
				if (j%t1 == 0){
					if (flag == 0){
						t2 = j;
						flag = 1;
					}
					else if (flag == 1){
						merge(j, t2, l);
						j += t1;
					}

				}
				else j += t1;
			}
		}
		mys.clear();
		repi(l, r){
			ll t1 = parent(a[i - l], l);
			mys.insert(t1);
		}
		printf("Case #%d: %d\n", z, mys.size());

	}
}