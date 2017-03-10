#include <iostream>
#include <stdio.h>
using namespace std;
#include <algorithm>
#define sc(x) scanf("%lld",&x)
typedef long long ll;

const ll mod=1000007ll;
int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	{
		ll n;sc(n);
		ll t1=n*(n+1);
		ll t2=(n*(n-1));
		t2/=2;
		ll t3=(t1+t2)%mod;
		printf("%lld\n",t3);



	}
} 