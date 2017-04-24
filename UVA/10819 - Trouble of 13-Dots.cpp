#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
const int N = 105;

int price[N];
int fav[N];
int dp[N][10005];
int money;
int n;

void init(){
	fori(N){
		forj(10005){
			dp[i][j] = -1;
		}
	}	
}
int foo(int idx, int moneyRem){
	if (moneyRem < 0 && money<=1800)return -1*inf;
	if (moneyRem < -200)return -1 * inf;
	if (idx == n){
		if (money - moneyRem <= 2000 && moneyRem < 0)return -1 * inf;
		return 0;
	}
	if (dp[idx][moneyRem] != -1)return dp[idx][moneyRem];
	return dp[idx][moneyRem] = max(foo(idx + 1, moneyRem), fav[idx] + foo(idx + 1, moneyRem - price[idx]));
}

int main(){
	//freopen("input.txt", "r", stdin);
	while (cin>>money){		
		sc(n);
		fori(n){
			sc(price[i]);
			sc(fav[i]);
		}
		
		init();
		int t1 = foo(0, money);
		printf("%d\n", t1);
	}
}