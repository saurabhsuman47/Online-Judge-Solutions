#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
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

set<pii> S[N];
int n;

bool check(int idx, pii p){
	set<pii> ::iterator it;
	pii tp;
	for (it = S[idx].begin(); it != S[idx].end(); it++){
		tp = *it;
		if (tp.first < p.first && tp.second < p.second)return true;
		if (tp.first >= p.first)return false;
	}
	return false;
}

int find_position(pii p){
	int start = 1, end = n, sol = 0;;
	while (start <= end){
		int mid = (start + end) / 2;
		if (check(mid, p)){
			sol = mid;
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	return sol + 1;
}

int main(){
	//freopen("input.txt", "r", stdin);
	sc(n);
	fork(n){
		int x, y;
		sc(x); sc(y);
		pii P = make_pair(x, y);
		int pos = find_position(P);
		S[pos].insert(P);
		set<pii> ::iterator it,temp_it;
		it = S[pos].find(P);
		it++;
		while (it != S[pos].end()){
			P = *it;
			if (P.first >= x && P.second >= y){
				temp_it = it;
				it++;
				S[pos].erase(temp_it);
			}
			else it++;
		}		

	}
	repi(1, n+1){
		if (S[i].size() == 0){
			printf("%d\n", i - 1);
			break;
		}
	}

}