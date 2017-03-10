#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
#define fori(n) for(int i=1;i<=n;i++)
#define forj(n) for(int j=1;j<=n;j++)
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))

const int N = 10005;
const int inf = 100000000;
const ll mod = 10000007;

int a[N];

int main(){
	//freopen("input.txt", "r", stdin);
	int t;
	sc(t);
	for(int z=1;z<=t;z++)
	{
		int n;
		sc(n);
		fori(n){
			sc(a[i]);
		}
		int sol=0;
		forj(32){
			int count0=0,count1=0;
			fori(n){
				int t1=a[i]%2;
				if(t1==0)count0++;
				else count1++;
				a[i]/=2;
			}
			sol=(sol+count0*count1*2)%mod;

		}
		printf("Case %d: %d\n",z,sol);
	}
	
}