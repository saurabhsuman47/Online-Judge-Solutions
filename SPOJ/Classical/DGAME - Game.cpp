#include <iostream>
using namespace std;
#include <cstdio>


#define sc(x) scanf("%d",&(x))
#define scl(x) scanf("%lld",&(x))
typedef long long ll;
const ll mod = 1000000007;

ll exp(ll n){
	ll a=2;
	ll result=1;
	while(n!=0){
		if(n%2==1)result=(result*a)%mod;
		a=(a*a)%mod;
		n/=2;
	}
	return result;
}

ll foo(ll n){
	ll a=2;
	while(a*2<=n){
		a*=2;
	}
	return (n-a+1);
}

int main() 
{	//freopen("input.txt","r",stdin);
	
	int t;
	sc(t);
	while(t--){
		ll n;
		scl(n);
		ll ans=0;
		ll t1=n%4;
		
		switch(t1)
		{
			case 0 : ans=foo(n);break;
			case 1 : ans=(n+1)/2;break;
			case 2 : ans=foo(n);break;
			case 3 : ans=0;break;
		}

		cout<<exp(n)<<" "<<ans<<endl;
	}
 
} 