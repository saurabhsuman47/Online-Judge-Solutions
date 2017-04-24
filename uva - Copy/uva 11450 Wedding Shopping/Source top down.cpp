#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
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

typedef vector<int> myv;
myv arr[21];
int m, c;
int dp[205][21];

int foo(int moneyRemaining, int garment){
	if (moneyRemaining < 0) return -1*inf;
	if (garment == c)return 0;
	if (dp[moneyRemaining][garment] != -1)return dp[moneyRemaining][garment];
	int result = -1*inf;
	fori(arr[garment].size()){
		result = max(result, arr[garment][i]+foo(moneyRemaining - arr[garment][i], garment + 1));
	}
	return dp[moneyRemaining][garment] = result;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){

		sc(m); sc(c);
		
		fori(c){
			int t1;
			sc(t1);
			arr[i].clear();
			forj(t1){
				int t2; sc(t2);
				arr[i].push_back(t2);
			}
		}
		memset(dp, -1, sizeof dp);
		int t1 = foo(m, 0);
		if (t1 < 0){
			printf("no solution\n");
		}
		else printf("%d\n", t1);

	}
}