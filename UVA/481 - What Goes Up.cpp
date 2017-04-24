#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

#define fori(x) for(int i=0;i<x;i++)

const ll inf = 100000000000;
const int N = 100005;

ll a[N];
int b[N];

struct set_compare{
	bool operator() (const pli& lhs, const pli& rhs)const{
		if (lhs.first != rhs.first){
			return lhs.first < rhs.first;
		}
		else{
			return lhs.second > rhs.second;
		}
	}
};

set<pli, set_compare> mys;
set<pli, set_compare> ::iterator it, pit;
pli p1;
stack<ll> S;

int main(){
	freopen("input.txt", "r", stdin);
	int n=0;
	while (cin >> a[n]){
		b[n] = -1;
		n++;
	}
	int idx = 0;
	fori(n){
		p1 = make_pair(a[i], i);
		mys.insert(p1);
		it = mys.find(p1);
		if (it != mys.begin()){
			pit = it;
			pit--;
			b[i] = (*pit).second;
		}
		it++;
		if (it != mys.end()){
			mys.erase(it);
		}		
	}
	cout << mys.size() << endl << "-" << endl;	
	
	it = mys.end();
	it--;
	ll t1;
	idx = (*it).second;
	while (true){
		if (idx == -1)break;
		t1 = a[idx];
		idx = b[idx];
		S.push(t1);
	}
	while (!S.empty()){
		cout << S.top() << endl;
		S.pop();
	}

}