#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <sstream>
#include <map>
#include <set>
using namespace std;

typedef long long ll;



const ll mod=1000000007ll;
double eps=1e-8;

	
#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&x)
#define pb push_back
#define mp make_pair
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)

ll exp(ll a)
{
	ll result=1;
	ll t1=1000000005;
	while(t1!=0)
	{
		if(t1%2==1)result=(a*result)%mod;
		a=(a*a)%mod;
		t1/=2;
	}
	return result;
}

ll fact[1005];

ll ncr(int n,int r)
{
	ll t1=fact[n];
	ll t2=(fact[n-r]*fact[r])%mod;
	ll t3=exp(t2);
	t3=(t1*t3)%mod;
	return t3;


}


////************
int main()
{
	fact[0]=1;fact[1]=1;

	for(ll i=2;i<1001;i++)
	{
		fact[i]=(i*fact[i-1])%mod;
	}
	int tt;
	sc(tt);
	while(tt--)
	{
		ll n,m;
		scl(n);scl(m);
		cout<<ncr(n+m,n)<<endl;
	}
}
