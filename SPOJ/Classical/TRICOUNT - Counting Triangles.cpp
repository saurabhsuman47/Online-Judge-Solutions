#include <iostream>
using namespace std;
#include <cstdio>
typedef long long ll;
#define scl(x) scanf("%lld",&(x))


int main() 
{	
	int t;
	scanf("%d",&t);
	ll * d=new ll[1000001];	d[1]=1;
	ll k;ll ii;
	for(ll i=2;i<=1000001;i++)
	{
		
		if(i%2==0){ll tt=(i*(i+1))/2;ii=i/2;ll tt1=ii*(ii+1);k=tt-tt1;}
		else if(i&1){k+=ii;}
		d[i]=d[i-1]+(i*(i+1))/2+k;
	}

	for(int pp=0;pp<t;pp++)
	{
		ll n;
		scl(n);
		cout<<d[n]<<endl;

	}
	
}