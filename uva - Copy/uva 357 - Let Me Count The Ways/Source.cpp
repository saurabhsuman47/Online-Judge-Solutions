#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define fori(x) for(ll i=0;i<x;i++)
#define forj(x) for(ll j=0;j<x;j++)

const int N = 30005;
ll a[] = { 0,1, 5, 10, 25, 50 };
ll dp[N][7];

ll foo(ll money, ll n){
	if (money == 0)return 1;
	if (n == 0 || money < 0)return 0;
	if (dp[money][n] != -1)return dp[money][n];
	return dp[money][n] = { foo(money, n - 1) + foo(money - a[n], n) };
}

void init(){
	fori(N){
		forj(7){
			dp[i][j] = -1;
		}
	}
}


int main(){
	//freopen("input.txt", "r", stdin);
	ll money;
	init();
	while (cin >> money){
		ll t1 = foo(money, 5);
		if (t1 != 1){
			printf("There are %lld ways to produce %lld cents change.\n", t1, money);
		}
		else{
			printf("There is only %lld way to produce %lld cents change.\n", t1, money);
		}
		
	}
}