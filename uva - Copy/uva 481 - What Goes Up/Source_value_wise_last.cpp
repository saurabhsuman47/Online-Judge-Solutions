//#include <cmath>
//#include <cstdio>
//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <map>
//#include <stack>
//using namespace std;
//
//#define sc(x) scanf("%d",&x)
//#define scl(x) scanf("%lld",&x)
//#define fori(x) for(int i=0;i<x;i++)
//#define forj(x) for(int j=0;j<x;j++)
//#define fork(x) for(int k=0;k<x;k++)
//#define repi(a,b) for(int i=a;i<=b;i++)
//#define repj(a,b) for(int j=a;j<=b;j++)
//typedef long long ll;
//
//const ll inf = 20000000000000;
//const int N = 1000005;
//
//ll a[N];
//multiset<ll> mys;
//multiset<ll> ::iterator it, pit;
//map<ll, int> lismap;
//stack<ll> S;
//struct node{
//	int val;
//	int idx;
//} lis[N];
//
//bool comp(const node& lhs, const node& rhs){
//	if (lhs.val == rhs.val){
//		return lhs.idx < rhs.idx;
//	}
//	else{
//		return lhs.val > rhs.val;
//	}
//}
//
//int main(){
//	freopen("input.txt", "r", stdin);
//	int n = 0;
//	while (cin >> a[n]){
//		n++;
//	}
//	int idx = 0;
//	fori(n){
//		//cout << i << endl;
//		mys.insert(a[i]);
//		/*for (it = mys.begin(); it != mys.end(); it++){
//			cout << (*it) << " ";
//		}
//		cout << endl;*/
//		it = mys.lower_bound(a[i]);
//		pit = it;	
//		it++;
//		if (it != mys.end()){
//			mys.erase(it);
//		}
//		if (pit != mys.begin()){
//			pit--;
//			lismap[a[i]] = lismap[(*pit)]+1;
//			lis[i].val = lismap[a[i]];
//		}
//		else{
//			lismap[a[i]] = 1;
//			lis[i].val = 1;
//		}
//		lis[i].idx = i;
//		
//
//		/*for (it = mys.begin(); it != mys.end(); it++){
//		cout << (*it) << " ";
//		}
//		cout << endl << endl;;*/
//		
//	}
//	cout << mys.size() << endl << "-" << endl;
//	sort(lis, lis + n,comp);
//	int ii = mys.size();
//	/*fori(n){
//		cout << lis[i].val << " ";
//	}
//	cout << endl;
//	fori(n){
//		cout << lis[i].idx << " ";
//	}*/
//	//cout << endl;
//	ll t1 = -1*inf;
//	ll t2 = inf;
//	/*fori(n){
//		if (lis[i].val == ii && a[lis[i].idx] < t1){
//			ii--;
//			t1 = a[lis[i].idx];
//			S.push(t1);
//		}
//	}*/
//	int k=0;
//	while (ii > 0){
//		if (lis[k].val == ii){
//			if (a[lis[k].idx] > t1 && a[lis[k].idx ]< t2)t1 = a[lis[k].idx];
//			k++;
//		}
//		else{
//			S.push(t1);
//			t2 = t1;
//			ii--;
//			t1 = -1*inf;
//			
//		}
//	}
//	while (!S.empty()){
//		cout << S.top() << endl;
//		S.pop();
//	}
//
//
//	
//
//}