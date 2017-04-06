#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

#define sc(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define pr(x) printf("%lld\n", x)
typedef long long ll;

int main(){
	freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int z = 1; z <=t; z++){
		ll x,y;
		int q;
		scl(x);scl(y);sc(q);
		set<ll> sx, sy;
		multiset<ll> mx, my;
		set<ll>::iterator itl, itr;
		multiset<ll>::iterator it, ito, it1;
		sx.insert(0); sx.insert(x);
		sy.insert(0); sy.insert(y);
		mx.insert(x); my.insert(y);
		for(int i = 0; i < q; i++){
			int axis;
			ll val;
			sc(axis); scl(val);
			if(axis == 0){
				if(sx.find(val) == sx.end()){
					itl = sx.lower_bound(val); itl--;
					itr = sx.upper_bound(val);
					ll len = *itr - *itl;
					it = mx.find(len);
					mx.erase(it);
					sx.insert(val);
					mx.insert(val - *itl);
					mx.insert(*itr - val);
				}
				it = mx.end();
				it--;
				ito = my.end();
				ito--;
				pr((*it)*(*ito));
			}
			else{
				if(sy.find(val) == sy.end()){
					itl = sy.lower_bound(val); itl--;
					itr = sy.upper_bound(val);
					ll len = *itr - *itl;
					it = my.find(len);
					my.erase(it);
					sy.insert(val);
					my.insert(val - *itl);
					my.insert(*itr - val);
				}				
				it = my.end();
				it--;
				ito = mx.end();
				ito--;
				pr((*it)*(*ito));
			}
			
		}
	}
	
}

