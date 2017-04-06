#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

#define sc(x) scanf("%d", &x)
#define pr(x) printf("%lld\n", x)
typedef long long ll;

int main(){
	// freopen("input.txt", "r", stdin);	
	int x,y,q;
	sc(x);sc(y);sc(q);
	set<int> sx, sy;
	multiset<int> mx, my;
	set<int>::iterator itl, itr;
	multiset<int>::iterator it, ito, it1;
	sx.insert(0); sx.insert(x);
	sy.insert(0); sy.insert(y);
	mx.insert(x); my.insert(y);
	for(int i = 0; i < q; i++){
		char axis; int val;
		cin>>axis; sc(val);
		if(axis == 'V'){
			if(sx.find(val) == sx.end()){
				itl = sx.lower_bound(val); itl--;
				itr = sx.upper_bound(val);
				int len = *itr - *itl;
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
			pr((ll)(*it)*(*ito));
		}
		else{
			if(sy.find(val) == sy.end()){
				itl = sy.lower_bound(val); itl--;
				itr = sy.upper_bound(val);
				int len = *itr - *itl;
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
			pr((ll)(*it)*(*ito));
		}
		
	}
	
	
}


