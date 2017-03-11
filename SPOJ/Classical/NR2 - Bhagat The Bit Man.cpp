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

const int N = 1000005;
const int inf = 100000000;
const ll mod = 10000007;

ll a[N];
ll bit[64];

int main(){
	//freopen("input.txt", "r", stdin);

	int n;
	sc(n);
	fori(n){
		scl(a[i]);
	}
	ll sol=0;
	forj(64){
		bit[j]=0;
		int count0=0,count1=0,flag=0;
		fori(n){
			if(flag==1){
				a[i]=a[i]>>1;
				continue;
			}
			ll t1=a[i]%2;
			if(t1==0)count0++;
			else count1++;			
			if(count0!=0 && count1!=0){
				bit[j]=1;
				flag=1;
			}
			a[i]=a[i]>>1;
		}
		
		

	}
	
	for(int j=64;j>=1;j--){
		sol*=2;
		sol+=bit[j];
	}
	printf("%lld\n", sol);

		
	
	
}