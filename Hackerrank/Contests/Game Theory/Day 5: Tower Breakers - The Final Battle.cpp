#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
#define fori(x) for(int i=0;i<x;i++)
#define forj(x) for(int j=0;j<x;j++)
#define fork(x) for(int k=0;k<x;k++)
#define repi(a,b) for(int i=a;i<=b;i++)
#define repj(a,b) for(int j=a;j<=b;j++)
const int N = 501;

ll a[100000];



int main(){
	//freopen("input.txt", "r", stdin);
	a[0]=1;	

	for(ll i=1;i<=130;i++){
		ll t1;
		ll j=1;
		ll sol=0;
		while(true){
			ll jj=j*j;
			t1=i-jj;
			if(t1<0)break;
			sol+=a[t1];
			j++;
		}
		a[i]=sol;
	}
	
	int t;
	sc(t);
	for (int z = 1; z <= t; z++){
		ll n;
		scl(n);
		int sol=1;
		fori(122){
			if(a[i]>=n){
				sol=i;
				break;
			}
		}
		cout<<sol<<endl;
		
	}
}
