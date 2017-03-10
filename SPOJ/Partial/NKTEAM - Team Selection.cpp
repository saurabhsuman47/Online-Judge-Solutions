#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

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
typedef pair<int, int> P;


struct score{
	int a, b, c;
};

score arr[N];
int bit[N];

bool sorter(const score& lhs, const score& rhs){
	return lhs.a < rhs.a;
}

void init(){
	fori(N){
		bit[i] = inf;
	}
}

void update(int idx, int value){
	while (idx<=N){
		bit[idx] = min(bit[idx], value);
		idx += (idx & -idx);
	}
}

int query(int idx){
	int result = inf;
	while (idx > 0){
		result = min(result, bit[idx]);
		idx -= (idx & -idx);
	}
	return result;
}


int main(){
	//freopen("input.txt", "r", stdin);
	
		int n;
		sc(n);
		fori(n){
			sc(arr[i].a);
		}
		fori(n){
			sc(arr[i].b);
		}
		fori(n){
			sc(arr[i].c);
		}
		sort(arr, arr + n, sorter);
		
		int count = 0;
		init();

		fori(n){
			int t1 = query(arr[i].b);
			if (arr[i].c > t1)continue;
			update(arr[i].b, arr[i].c);
			count++;
		}

		printf("%d\n", count);
	
}